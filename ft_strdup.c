#include "libft.h"

char *ft_strdup(const char *s)
{
  size_t size;
  char *result;

  size = ft_strlen(s) + 1;
  result = (char *) ft_calloc(size, sizeof(char));
  if (result != NULL)
    ft_strlcpy(result, s, size);
  return (result);
}
