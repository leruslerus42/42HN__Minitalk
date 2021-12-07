# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 02:03:11 by rrajaobe          #+#    #+#              #
#    Updated: 2021/12/07 02:28:52 by rrajaobe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minitalk

FLAGS = -Wall -Wextra -Werror

LIBFTPATH =	./libft/

PRINTFPATH = ./printf/

LIBFT =	libft.a

PRINTF = libftprintf.a

OBJ := $(*.o)

SRC =		./src/server.c \
			./src/client.c \
			
all: $(NAME)

$(NAME): fclean
	make -C ${LIBFTPATH}
	make -C ${PRINTFPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	mv ${PRINTFPATH}${PRINTF} ${PRINTF}
	$(CC) $(FLAGS) ${LIBFT} ${PRINTF} ${SRC} -o ${NAME}

clean:
	rm -f ./libft/*.o
	rm -f ./printf/*.o
	rm -f *.o
	
fclean: clean
	rm -f ${LIBFT} ${PRINTF} ${OBJ} $(NAME)

re: fclean $(NAME)