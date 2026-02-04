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
CFLAGS += -MD -Wall -Wextra -Werror -I./inc $(FT_EXTRA_CFLAGS)
# -MD to generate the .d files in $(DEPS)

NAME = libft
LIB = $(NAME).a
HEADER = $(addprefix ./inc/, \
	libft.h libft_buf.h libft_char.h libft_fmt.h libft_io.h libft_iol.h libft_ll.h \
	libft_locale.h libft_math.h libft_mem.h libft_str.h libft_toa.h)

SRC_DIR = ./src
BIN_DIR = ./bin

FT_LIB_PKGS = arr buf char fmt io iol ll math mem os str toa

# load SECT_$(pkg) for every pkgs
-include $(FT_LIB_PKGS:%=$(SRC_DIR)/%.mk)

C_FILES = $(foreach p, $(FT_LIB_PKGS), $(addprefix $(p)/, $(SECT_$(p))))

GIT_IGNORE += .depend
GIT_IGNORE += .gdb_history lldb_bugreport.txt

GIT_IGNORE += $(BIN_DIR)
SRCS = $(addprefix $(SRC_DIR)/, $(C_FILES))
OBJS = $(C_FILES:%.c=$(BIN_DIR)/%.o)
DEPS = $(OBJS:.o=.d)
DEV_FILES = .gitignore compile_flags.txt
DOC_FOLDER = doc
GIT_IGNORE += $(OBJS) $(DEPS) $(DEV_FILES)

SELF = $(firstword $(MAKEFILE_LIST))

# phony targets
all: $(NAME)
re: clean all
fclean: clean dev_clean doc_clean
clean:
	$(RM) $(OBJS) $(LIB) $(DEPS)
	$(RM) -r $(BIN_DIR)
dev: $(DEV_FILES)
dev_clean:
	$(RM) $(DEV_FILES)
$(NAME): $(LIB)
.PHONY: fclean clean re all dev doc dh doc_clean

# rules to generate documentation
GIT_IGNORE += /doc
doc: $(C_FILES) $(HEADER) Doxyfile
	doxygen

dh: doc_clean doc
	(cd "./$(DOC_FOLDER)/html" && python3 -m http.server)

doc_clean:
	$(RM) -r Doxyfile "./$(DOC_FOLDER)"

GIT_IGNORE += Doxyfile
Doxyfile: $(SELF)
	@echo -n > $@
	@echo 'PROJECT_NAME = "Libft"' >> $@
	@echo 'INPUT = '$(HEADER) >> $@
	@echo 'EXTRACT_ALL = YES' >> $@
	@echo 'QUIET = YES' >> $@
	@echo "OUTPUT_DIRECTORY  = ./$(DOC_FOLDER)" >> $@

# development helper files
compile_flags.txt: CFLAGS += $(NIX_CFLAGS_COMPILE)
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
-include $(DEPS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

GIT_IGNORE += $(LIB)
libft.a: $(OBJS)
	$(AR) -src $@ $^
