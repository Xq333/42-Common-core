dc = docker-compose -f
files = ./srcs/docker-compose.yml 

all:
	$(dc) $(files) build
	$(dc) $(files) up -d

down:
	$(dc) $(files) down

clean:
	$(dc) $(files) down 

fclean: clean
	docker system prune -a --volumes

re: clean all
