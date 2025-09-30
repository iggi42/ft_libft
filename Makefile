# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 16:10:11 by fkruger           #+#    #+#              #
#    Updated: 2025/09/30 20:38:16 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS +=-Wall -Wextra -Werror
NAME = libft
SRC = *.c lib_ft.h

OBJ = $(SRC:.c=.o)

libft.a: $(SRC)
$(NAME): libft.a
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:

