#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
  size_t len;

  len = ft_strlen(s);
  (void) write(fd, s, len);
}

/*
int main(void)
{
  ft_putstr_fd("lmao\n", 1);
}
*/
