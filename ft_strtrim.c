#include "libft.h"

char *ft_strtrim(char const *src, char const *set)
{
  char *result;
  size_t src_i;
  size_t res_i;

  src_i = 0;
  res_i = 0;
  result = ft_calloc(ft_strlen(src), sizeof(char));
  while (result != NULL && *(src + src_i) != '\0')
  {
    if( ft_strchr(set, *(src + src_i)) == NULL )
    {
      *(result + res_i) = *(src + src_i);
      res_i++;
    }
    src_i++;
  }
  return (result);
}
