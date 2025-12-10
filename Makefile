# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 16:10:11 by fkruger           #+#    #+#              #
#    Updated: 2025/12/05 22:55:50 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# configuration variables
CC = cc
CFLAGS += -MD -Wall -Wextra -Werror -g
# -MD to generate the .d files in $(DEPS)

NAME = libft
HEADER = $(NAME).h
LIB = $(NAME).a

GIT_IGNORE += .depend
GIT_IGNORE += .gdb_history lldb_bugreport.txt

BASE_CC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_tolower.c ft_toupper.c

BASE_MEM = ft_bzero.c ft_calloc.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memchr.c \
 ft_memmove.c ft_iszero.c ft_free.c

BASE_STR = ft_str_alloc.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_itoa.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
		ft_atoi.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_strchr.c

BASE_IO = ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c  ft_putnbr_fd.c
BASE_LL = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ft_lstfold.c

SRCS += $(BASE_CC) $(BASE_MEM) $(BASE_STR) $(BASE_IO) $(BASE_LL)

EXTRA_TOA_B = ft_btoa.c ft_btoa_b.c ft_btoa_bl.c
EXTRA_TOA_I = ft_itoa.c ft_itoa_b.c ft_itoa_bl.c 
EXTRA_TOA_L = ft_ltoa.c ft_ltoa_b.c ft_ltoa_bl.c
EXTRA_TOA_UL = ft_ultoa.c ft_ultoa_b.c ft_ultoa_bl.c
EXTRA_TOA_P = ft_ptoa.c ft_ptoa_b.c ft_ptoa_bl.c
EXTRA_TOA = $(EXTRA_TOA_B) $(EXTRA_TOA_I) $(EXTRA_TOA_L) $(EXTRA_TOA_UL) $(EXTRA_TOA_P)

EXTRA_IOL = ft_iol_pp.c ft_iol_pp_el.c ft_iol_write.c ft_iol_del.c ft_iol_el_alloc.c ft_iol_free_always.c \
			ft_iol_size.c ft_iol_str.c  ft_iol_str_l.c ft_iol_append.c
EXTRA_BUF = ft_buf_cat.c ft_buf_cp.c ft_buf_free.c ft_buf_new.c ft_buf_read.c ft_buf_split.c
EXTRA_FORMAT = ft_printf.c ft_fmt_parse.c ft_fmt_apply.c ft_fmt_str.c
EXTRA_FORMAT += ft_fmt_set_c.c ft_fmt_set_hex.c ft_fmt_set_i.c ft_fmt_set_ptr.c ft_fmt_set_str.c ft_fmt_set_ui.c

SRCS += $(EXTRA_TOA) $(EXTRA_IOL) $(EXTRA_BUF) $(EXTRA_FORMAT)

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
DEV_FILES = .gitignore compile_flags.txt
DOC_FOLDER = doc
GIT_IGNORE += $(OBJS) $(DEPS) $(DEV_FILES)

SELF=$(firstword $(MAKEFILE_LIST))

GIT_IGNORE += $(LIB)
$(LIB): $(OBJS)
	$(AR) -src $@ $^

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
ifeq ($(shell hostname), personal-dev)
%_fd.o: CFLAGS += -Wno-unused-result
endif
-include $(DEPS)

