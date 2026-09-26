# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dev.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/10 23:12:14 by fkruger           #+#    #+#              #
#    Updated: 2026/04/10 23:12:19 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEV_FILES = .gitignore compile_flags.txt
# DEV_FILES += compile_flags.json
GIT_IGNORE += $(DEV_FILES) compile_flags.json
# rules to generate documentation
.PHONY:  dev doc dh doc_clean
dev: $(DEV_FILES)
dev_clean:
	$(RM) $(DEV_FILES)
fclean: dev_clean doc_clean

GIT_IGNORE += /doc
doc: doc/html
doc/html: doc/ $(DOC_HEADER) Doxyfile
	doxygen

dh: doc_clean doc
	(cd "./$(DOC_FOLDER)/html" && python3 -m http.server)

doc_clean:
	$(RM) -r Doxyfile "./$(DOC_FOLDER)"

GIT_IGNORE += Doxyfile
Doxyfile: $(SELF)
	@echo -n > $@
	@echo 'PROJECT_NAME = "$(NAME)"' >> $@
	@echo 'INPUT = $(DOC_HEADER)' >> $@
	@echo 'EXTRACT_ALL = YES' >> $@
	@echo 'QUIET = YES' >> $@
	@echo "OUTPUT_DIRECTORY  = ./$(DOC_FOLDER)" >> $@

# development helper files
compile_flags.txt: CFLAGS += $(NIX_CFLAGS_COMPILE) "-DFT_APP_NAME=$(NAME)"
compile_flags.txt: $(SELF)
	@echo setup $@
	@echo -n > $@
	@for flag in $(CFLAGS); do \
	 	echo $$flag >> $@ ; \
	done

.gitignore: $(SELF)
	@echo setup $@
	@echo -n > $@
	@for ig in $(GIT_IGNORE); do \
		echo $$ig >> $@ ; \
	done

