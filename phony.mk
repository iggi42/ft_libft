## TODO ft header
# phony targets
all: $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
fclean: clean
	$(RM) $(NAME) $(LIB)
clean:
	$(RM) $(OBJS) $(LIB) $(DEPS)
	$(RM) -r $(BIN_DIR)
$(NAME): $(LIB)
.PHONY: fclean clean re all $(NAME)
