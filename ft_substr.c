#include "libft.h"


// this should return NULL, not an empty string on start (ft_strlen(s) < start)
char *ft_substr(const char *s, unsigned int start, size_t len)
{
  char *result;

  if (ft_strlen(s) < start)
    return ("");
  result = ft_calloc(len + 1, sizeof(char));
  return (ft_memcpy(result, s + start, len));
}
