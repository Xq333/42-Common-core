# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 19:50:26 by pfaria-d          #+#    #+#              #
#    Updated: 2023/06/22 16:04:50 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR			= \033[0m
WHITE			= \033[1;37m
RED				= \033[0;31m
LIGHTPURPLE		= \033[1;35m
CLEAR			= \r\033[K
LIGHTGRAY		= \033[0;37m
GREEN			= \033[0;32m

SRC 		= ft_printf_bonus.c \
			  utilities_bonus.c \
			  utilities2_bonus.c \
			  utilities3_bonus.c \
			  exec_bonus.c \
			  exec2_bonus.c \
			  bonus.c \
			  bonus2_bonus.c \

SRCBONUS	= ft_printf_bonus.c \
			  utilities_bonus.c \
			  utilities2_bonus.c \
			  utilities3_bonus.c \
			  exec_bonus.c \
			  exec2_bonus.c \
			  bonus.c \
			  bonus2_bonus.c \

OBJS 		= $(SRC:.c=.o)

OBJSBONUS 	= $(SRCBONUS:.c=.o)

GCC 		= gcc

FLAGS		= -Wall -Wextra -Werror 

RM  = rm -f

NAME = libftprintf.a

ifdef 	MAKEBONUS
endif

NORM = $(shell norminette | grep Error: | wc -l | awk '{print $1}' | xargs)

NORMINETTE = 0

ifeq (${NORM}, ${NORMINETTE})
	NORMINETTE = "${WHITE}NORM : ${GREEN}OK${NOCOLOR}\n"
else
	NORMINETTE = "${WHITE}NORM : ${RED}${NORM} errors${NOCOLOR}\n"
endif

all: 		$(NAME)

.c.o:
			@printf "${CLEAR}🌂 ${LIGHTPURPLE}%s ${LIGHTGRAY}compiling...${NOCOLOR}" ${notdir $<}
			@$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@$(GCC) $(FLAGS)  -c -I ./ ${SRC}
			@ar rcs $(NAME) $(OBJS)
			@echo ${NORMINETTE}

bonus:		
			@make re

clean:
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}.o files  ${LIGHTGRAY}cleaned\n${NOCOLOR}"
			@$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}Printf ${LIGHTGRAY}cleaned\n${NOCOLOR}"
			@$(RM) $(NAME)

re:			fclean $(NAME)
