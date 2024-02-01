# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 12:11:37 by pfaria-d          #+#    #+#              #
#    Updated: 2023/01/19 11:44:30 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c utils/utils.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c utils/utils6.c stack/stackutils1.c stack/stackmovesa.c stack/stackmovesb.c moves/s.c moves/p.c moves/r.c moves/rr.c sorting/sorting.c ft_printf/ft_printf_nbrb.c ft_printf/ft_printf_utils1.c ft_printf/ft_printf.c
SRCB = bonus/checker_bonus.c bonus/gnl_bonus/get_next_line_bonus.c bonus/gnl_bonus/get_next_line_utils_bonus.c bonus/moves_bonus/p_bonus.c bonus/moves_bonus/s_bonus.c bonus/moves_bonus/rr_bonus.c bonus/moves_bonus/r_bonus.c bonus/utils_bonus/utils_bonus.c bonus/utils_bonus/utils4_bonus.c bonus/utils_bonus/utils2_bonus.c bonus/utils_bonus/utils3_bonus.c bonus/stack_bonus/stackmovesa_bonus.c bonus/stack_bonus/stackmovesb_bonus.c bonus/stack_bonus/stackutils1_bonus.c

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -rf

HFILE = push_swap.h
HFILEB = bonus/checker_bonus.h

NAME = push_swap
NAMEB = bonus/checker

all: $(NAME)

.c.o :
	$(GCC) -c $< -o $@

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJSB)
	$(GCC) $(OBJSB) -o $(NAMEB)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME) $(NAMEB)

re:			fclean $(NAME)

.PHONY: all clean fclean re bonus
