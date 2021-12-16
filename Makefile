# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 02:03:11 by rrajaobe          #+#    #+#              #
#    Updated: 2021/12/16 16:17:00 by rrajaobe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minitalk

FLAGS = -Wall -Wextra -Werror -fsanitize=address

SERVER = server

CLIENT = client

SRC_SERVER = ./src/server.c

SRC_CLIENT = ./src/client.c

OBJ_SERVER = $(SRC_SERVER: .c=.o)

OBJ_CLIENT = $(SRC_CLIENT: .c=.o)

LIBFTPATH =	./libft/

LIBFT =	libft.a

PRINTFPATH = ./printf/

PRINTF = libftprintf.a


all: libraries $(SERVER) $(CLIENT)

libraries:
	make -C ${LIBFTPATH}
	make -C ${PRINTFPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	mv ${PRINTFPATH}${PRINTF} ${PRINTF}
	
server: libraries $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)
	
client: libraries $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	
clean:
	rm -f ./libft/*.o
	rm -f ./printf/*.o
	rm -f *.o
	
fclean: clean
	rm -f ${LIBFT}  ${OBJ} $(NAME) $(SERVER) $(CLIENT) 
#${PRINTF}
re: fclean all