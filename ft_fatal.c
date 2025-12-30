#include <stdlib.h>
#include <stdio.h>

void ft_fatal(void)
{
	perror("LIBFT: ");
	exit(EXIT_FAILURE);
}
