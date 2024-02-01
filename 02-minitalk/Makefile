# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 12:11:48 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/16 14:32:02 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCA = server.c client.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_atoi.c extra/ft_printf_nbrb.c
SRCC = client.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_atoi.c extra/ft_printf_nbrb.c
SRCS = server.c extra/ft_printf.c extra/ft_printf_utils1.c extra/ft_printf_nbrb.c

OBJSA = $(SRCA:.c=.o)
OBJSC = $(SRCC:.c=.o)
OBJSS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = Minitalk.h

NAME = server
NAME1 = client

all: $(NAME) $(NAME1)

.c.o :
	$(GCC) -I $(HFILE) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJSS)
			$(GCC) -o $(NAME) $(OBJSS)

$(NAME1):	$(OBJSC)
			$(GCC) -o $(NAME1) $(OBJSC)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJSA)

fclean:		clean
			$(RM) server client

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

