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

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	print_char.c \
	print_str.c \
	print_int.c \
	print_unsint.c \
	print_hex.c  \
	print_void.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile ft_printf.h
			${CC} ${FLAGS} -I ./ -c $< -o $@

$(NAME):	${OBJECTS}
		ar rc ${NAME} ${OBJECTS}

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: 	all clean fclean re