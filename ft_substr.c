#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
  // TODO check if the string is actually at max len
  return (ft_strdup(s + start));
}
