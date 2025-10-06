# *************************************************************************** #
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
CFLAGS += -Wall -Wextra -Werror
NAME = libft
C_FILES = ft_lib_ctype.c ft_lib_mem.c ft_lib_str.c

HEADER = $(NAME).h
LIB = $(NAME).a
SRC = $(HEADER) $(C_FILES)
OBJ = $(C_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	ar -src $@ $^

$(NAME): libft.a
all: $(NAME)

fclean: clean
clean: 
	rm -f $(OBJ) $(LIB)

re: clean all
