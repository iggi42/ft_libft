#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
  size_t size;
  char *result;

  size = ft_strlen(s1) + ft_strlen(s2) + 1;
  result = ft_calloc(size, sizeof(char));
  if (result != NULL)
  {
    ft_strlcpy(result, s1, size);
    ft_strlcat(result, s2, size);
  }
  return (result);
}
