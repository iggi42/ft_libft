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
CFLAGS += -Wall -Wextra -Werror -g
NAME = libft
C_FILES = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			 ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memchr.c ft_strchr.c \
			 ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
			 ft_tolower.c ft_toupper.c ft_atoi.c ft_strnstr.c ft_substr.c ft_strjoin.c \
			 ft_strtrim.c

HEADER = $(NAME).h
LIB = $(NAME).a
SRC = $(HEADER) $(C_FILES)
OBJ = $(C_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	ar -src $@ $^

$(NAME): $(LIB)
all: $(NAME)

fclean: clean
clean: 
	rm -f $(OBJ) $(LIB)

re: clean all

.PHONY: fclean clean re all
