
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  char buffer;
  
  if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
    return (0);
  buffer = *s1 - *s2;
  if (buffer == 0)
    return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
  else
    return (buffer);
}
