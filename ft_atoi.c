#include "libft.h"
#include <stdbool.h>

static bool ft_isspace(const char c)
{
  return (ft_strchr(" \f\n\r\t\v", c) != NULL);
}

int ft_atoi(const char *nptr)
{
  char *runner = (char *) nptr;
  while (ft_isspace(*runner))
    runner++;

  int sign = 1;
  while (*runner == '-')
  {
    sign *= -1;
    runner++;
  }

  long result = 0;
  while (ft_isdigit(*runner))
  {
    result = result * 10 + (*runner - 48);
    runner++;
  }
  return ((int) sign * result);
}
