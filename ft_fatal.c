#include <stdio.h>
#include <stdlib.h>

void	ft_fatal(void)
{
	perror("FATAL ERROR: ");
	exit(EXIT_FAILURE);
}
