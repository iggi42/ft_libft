
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char *result;
  size_t s_len;
  size_t i;

  i = 0;
  s_len = ft_strlen(s);
  result = ft_calloc(s_len + 1, sizeof(char));
  while (result != NULL && *(s + i) != '\0')
  {
    result[i] = f(i, s[i]);
    i++;
  }
  return (result);
}

/* char addOne(unsigned int i, char c) { return (i + c); }

#include <stdio.h>

int main(void)
{
  printf("joa,: \"%s\"\n", ft_strmapi("01234", addOne));
  return (0);
} */
