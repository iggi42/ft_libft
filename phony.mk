## TODO ft header
# phony targets
all:
	@$(MAKE) -j$(shell nproc) $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
fclean: clean
	$(RM) $(NAME) $(LIB) libft.d
clean:
	$(RM) $(OBJS) $(LIB) $(DEPS)
	$(RM) -r $(BIN_DIR)
$(NAME): $(LIB)
.PHONY: fclean clean re all $(NAME)
