# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 21:35:57 by teojimen          #+#    #+#              #
#    Updated: 2023/10/06 21:35:57 by teojimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a;

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

SRC = ft_isalnum.c ft_strlen.c ft_memset.c

OBJECTS = $(SRC:.c=.o)
CC = gcc

$(NAME):	${OBJECTS}
			ar rc ${NAME} ${OBJECTS}

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)