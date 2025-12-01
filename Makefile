# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 16:10:11 by fkruger           #+#    #+#              #
#    Updated: 2025/11/19 22:57:50 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# configuration variables
CC = cc
CFLAGS += -MD -Wall -Wextra -Werror
# -MD to generate the .d files in $(DEPS)

NAME = libft
HEADER = $(NAME).h
LIB = $(NAME).a
SRCS = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memchr.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_atoi.c ft_strnstr.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_memmove.c ft_split.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putchar_fd.c ft_itoa.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_lstfold.c ft_printf.c  ft_iol_pp.c ft_iol_pp_el.c ft_iol_write.c ft_iol_del.c \
			ft_ptoa.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
DEV_FILES = .gitignore compile_flags.txt
DOC_FOLDER = doc
GIT_IGNORE += $(OBJS) $(DEPS) $(DEV_FILES)

SELF=$(firstword $(MAKEFILE_LIST))

GIT_IGNORE += $(LIB)
$(LIB): $(OBJS)
	ar -src $@ $^

# phony targets
$(NAME): $(LIB)
all: $(NAME)
re: clean all
fclean: clean dev_clean doc_clean
clean:
	rm -f $(OBJS) $(LIB) $(DEPS)
dev: $(DEV_FILES)
dev_clean:
	rm -vf $(DEV_FILES)
.PHONY: fclean clean re all dev doc dh doc_clean

# %.o: %.c $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@

# rules to generate documentation
GIT_IGNORE += /doc
doc: $(C_FILES) $(HEADER) Doxyfile
	doxygen

dh: doc_clean doc
	(cd "./$(DOC_FOLDER)/html" && python3 -m http.server)

doc_clean:
	rm -rf "./$(DOC_FOLDER)"

GIT_IGNORE += Doxyfile
Doxyfile: $(SELF)
	@echo -n > $@
	@echo 'PROJECT_NAME = "Iggys Libft"' >> $@
	@echo 'INPUT = ./'$(HEADER) >> $@
	@echo 'EXTRACT_ALL = YES' >> $@
	@echo 'QUIET = YES' >> $@
	@echo "OUTPUT_DIRECTORY  = ./$(DOC_FOLDER)" >> $@

# development helper files
compile_flags.txt: $(SELF)
	@echo setup $@
	@echo -n > $@
	@for flag in $(CFLAGS); do \
	 	echo $$flag >> $@ ; \
	done

.gitignore: $(SELF)
	@echo setup $@
	@for ig in $(GIT_IGNORE); do \
		echo $$ig >> $@ ; \
	done

# core build rules
ifeq ($(shell hostname), goat)
%_fd.o: CFLAGS += -Wno-unused-result
endif
-include $(DEPS)

