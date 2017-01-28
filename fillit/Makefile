# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/03 16:36:01 by pswanson          #+#    #+#              #
#    Updated: 2016/11/26 22:48:51 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

SRC = fillit.c \
	fillit02.c \
	fillit03.c \
	fillit04.c \
	fillit05.c \
	fillit06.c \

OBJ = *.o

CFLAGS = -Wall -Wextra -Werror 

.PHONY: clean

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L ./ -lft

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
