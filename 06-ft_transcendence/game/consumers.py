from channels.generic.websocket import AsyncWebsocketConsumer
import json


class tournamentConsumer(AsyncWebsocketConsumer):
    users_in_room = {}
    winners = 0

    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = self.room_name
        self.player_id = None
        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        await self.accept()
        await self.send(text_data=json.dumps({
            'message': 'username',
        }))

    async def tournament_ready(self, event):
        await self.send(text_data=json.dumps({
            'players': event['players'],
            'message': 'ready',
        }))

    def get_group_size(self):
        return len(self.channel_layer.groups[self.room_group_name])

    async def disconnect(self, close_code):
        if self.player_id is not None and self.player_id in self.users_in_room:
            del self.users_in_room[self.player_id]
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        if message == 'disconnect_request':
            await self.close()
        elif message == 'username':
            username = text_data_json['username']
            self.player_id = text_data_json['player_id']
            self.users_in_room[self.player_id] = username
            if len(self.users_in_room) == 4:
                await self.channel_layer.group_send(
                    self.room_group_name,
                    {
                        'type': 'tournament_ready',
                        'players': self.users_in_room,
                    }
                )
        elif message == 'match_done':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'check_winners',
                    'message': 'check-winners',
                }
            )
            await self.close()
        elif message == 'finals':
            winner1 = text_data_json['winner1']
            winner2 = text_data_json['winner2']
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'go_finals',
                    'winner1': winner1,
                    'winner2': winner2,
                }
            )

    async def go_finals(self, event):
        try:
            winner1 = event['winner1']
            winner2 = event['winner2']
            await self.send(text_data=json.dumps({
                'message': 'finals',
                'winner1': winner1,
                'winner2': winner2,
            }))
        except Exception as e:
            print("Message go_finals not sent ", e)

    async def check_winners(self, event):
        try:
            message = event['message']
            await self.send(text_data=json.dumps({
                'message': message,
            }))
        except Exception as e:
            print("Message check not sent ", e)


class lobbyConsumer(AsyncWebsocketConsumer):

    users_in_room = {}

    async def connect(self):
        self.room_name = 'Matchmaking'
        self.room_group_name = 'lobby'
        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        await self.accept()
        roomSize = self.get_group_size()
        if roomSize == 1:
            self.player = "player1"
            await self.send(text_data=json.dumps({
                'message': 'username',
            }))
        elif roomSize == 2:
            self.player = "player2"
            await self.send(text_data=json.dumps({
                'message': 'username',
            }))

    async def match_ready(self, event):
        await self.send(text_data=json.dumps({
            'players': event['players'],
            'message': 'ready',
        }))

    def get_group_size(self):
        return len(self.channel_layer.groups[self.room_group_name])

    async def disconnect(self, close_code):
        del self.users_in_room[self.player]
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        if message == 'disconnect_request':
            await self.close()
        elif message == 'username':
            username = text_data_json['username']
            self.users_in_room[self.player] = username
            if len(self.users_in_room) == 2:
                await self.channel_layer.group_send(
                    self.room_group_name,
                    {
                        'type': 'match_ready',
                        'players': self.users_in_room,
                    }
                )


class gameConsumer(AsyncWebsocketConsumer):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.players_ready = {}
        self.users_in_room = {}

    async def connect(self):
        self.p1 = self.scope['url_route']['kwargs']['p1']
        self.p2 = self.scope['url_route']['kwargs']['p2']
        self.room_group_name = self.p1 + self.p2
        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        self.paddle_id = None
        await self.accept()

    async def player_joined(self, event):
        lenght = self.get_group_size()
        print("Player joinde in da place")
        await self.send(text_data=json.dumps({
            'players': event['players'],
            'message': 'joined',
            'len': lenght,
        }))

    def get_group_size(self):
        return len(self.channel_layer.groups[self.room_group_name])

    async def disconnect(self, close_code):
        self.users_in_room.clear()
        self.players_ready.clear()
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'player_left',
                'player': self.paddle_id,
            }
        )
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def player_left(self, event):
        try:
            await self.send(text_data=json.dumps({
                'player': event['player'],
                'message': 'left',
            }))
        except Exception as e:
            print("Message player_left not sent: ", e)

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json['message']
        if message == 'disconnect_request':
            await self.close()
        elif message == 'connexion':
            if text_data_json['player'] == self.p1:
                self.paddle_id = "paddle1"
                self.users_in_room[self.paddle_id] = 'p1'
            elif text_data_json['player'] == self.p2:
                self.paddle_id = "paddle2"
                self.users_in_room[self.paddle_id] = 'p2'
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'player_joined',
                    'players': self.users_in_room,
                }
            )
        elif message == 'add_player':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'add_player',
                    'player': text_data_json['player'],
                }
            )
        elif message == 'ready':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'markPlayerReady',
                    'player': text_data_json['player'],
                }
            )
        elif message == 'not_ready':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'not_ready',
                    'player': text_data_json['player'],
                }
            )
        elif message == 'player':
            await self.send(text_data=json.dumps({
                'message': 'init_paddle',
                'player1': self.p1,
                'player2': self.p2,
                'paddle_id': self.paddle_id,
            }))
        elif message == 'movement':
            paddle_movement = text_data_json['position']
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'paddle_move',
                    'paddle_id': self.paddle_id,
                    'movement': paddle_movement
                }
            )
        elif message == 'collision':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'collision',
                    'kind': text_data_json['kind'],
                    'ballX': text_data_json['ballX'],
                    'ballY': text_data_json['ballY'],
                    'scoreA': text_data_json['scoreA'],
                    'scoreB': text_data_json['scoreB'],
                }
            )

    async def add_player(self, event):

        if (self.paddle_id == 'paddle2'):
            self.users_in_room['paddle1'] = 'p1'
        elif (self.paddle_id == 'paddle1'):
            self.users_in_room['paddle2'] = 'p2'
        if self.paddle_id == None:
            self.paddle_id = event['player']
            self.users_in_room[self.paddle_id] = event['player']

    async def not_ready(self, event):
        player = event['player']
        await self.send(text_data=json.dumps({
            'message': 'player not ready',
            'playerId': player,
        }))
        del self.players_ready[player]

    async def collision(self, event):
        kind = {}
        kind['kind'] = event['kind']
        kind['ballX'] = event['ballX']
        kind['ballY'] = event['ballY']
        kind['scoreA'] = event['scoreA']
        kind['scoreB'] = event['scoreB']

        if kind['kind'] == 'goal':
            try:
                await self.send(text_data=json.dumps({
                    'message': 'goal',
                    'ball': kind['ballX'],
                    'scoreA': kind['scoreA'],
                    'scoreB': kind['scoreB'],
                }))
            except Exception as e:
                print("Message goal not sent: ", e)
        elif kind['kind'] == 'paddle':
            try:
                await self.send(text_data=json.dumps({
                    'message': 'paddle',
                    'ballX': kind['ballX'],
                    'ballY': kind['ballY'],
                }))
            except Exception as e:
                print("Message paddle not sent: ", e)

    async def paddle_move(self, event):
        try:
            await self.send(text_data=json.dumps({
                'paddle_id': event['paddle_id'],
                'movement': event['movement'],
                'message': 'paddle_move',
            }))
        except Exception as e:
            print("Message paddle_move not sent: ", e)

    async def markPlayerReady(self, paddle_id):
        player = paddle_id['player']
        self.players_ready[player] = True
        await self.send(text_data=json.dumps({
            'message': 'player ready',
            'player': paddle_id,
            'playerId': paddle_id,
        }))
        if len(self.players_ready) == 2:
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'start_game',
                    'message': 'game will start'
                }
            )

    async def start_game(self, event):
        await self.send(text_data=json.dumps({
            'message': event['message'],

        }))
