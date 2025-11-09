# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 16:10:11 by fkruger           #+#    #+#              #
#    Updated: 2025/10/29 04:58:53 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# configuration variables
CC = cc
CFLAGS += -Wall -Wextra -Werror -g
NAME = libft
C_FILES = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			 ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memchr.c ft_strchr.c \
			 ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
			 ft_tolower.c ft_toupper.c ft_atoi.c ft_strnstr.c ft_substr.c ft_strjoin.c \
			 ft_strtrim.c ft_memmove.c ft_split.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c \
			 ft_putendl_fd.c ft_putchar_fd.c ft_itoa.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			 ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 ft_lstmap.c

HEADER = $(NAME).h
LIB = $(NAME).a
SRC = $(HEADER) $(C_FILES)
OBJ = $(C_FILES:.c=.o)
DEV_FILES = .gitignore compile_flags.txt


# core build rules
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	ar -src $@ $^

# phony targets
$(NAME): $(LIB)
all: $(NAME)
re: clean all
fclean: clean dev_clean
clean:
	rm -f $(OBJ) $(LIB)
dev: $(DEV_FILES)
dev_clean:
	rm -vf $(DEV_FILES)
.PHONY: fclean clean re all dev

# development helper files
compile_flags.txt: $(firstword $(MAKEFILE_LIST))
	@echo setup $@
	@echo -n > $@
	@for flag in $(CFLAGS); do \
	 	echo $$flag >> $@ ; \
	done

.gitignore: $(firstword $(MAKEFILE_LIST))
	@echo setup $@
	@echo $@ > $@
	@echo compile_flags.txt >> $@
	@echo $(LIB) >> $@
	@echo '*.o' >> $@
	
