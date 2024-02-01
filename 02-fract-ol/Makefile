# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:49:47 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/22 16:56:40 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fract-ol.c sets/mandelbrot-set.c sets/mlxutils.c utils/ft_printf.c utils/ft_printf_nbrb.c utils/ft_printf_utils1.c utils/ft_strncmp.c utils/ft_atoi.c sets/julia-set.c sets/hooks.c sets/keyhooks.c sets/jkeyhooks.c sets/jhooks.c sets/bhooks.c sets/bkeyhooks.c sets/burningship-set.c

OBJS = $(SRC:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = fractol.h

NAME = fractol

all: $(NAME) 

.c.o :
	$(GCC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) fractol

re:			fclean $(NAME)

.PHONY: all clean fclean re

