/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:15:06 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/26 22:40:08 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	result;
	char	*runner;
	char	*old_run;

	result = 1;
	runner = ft_strchr(s + 1, c);
	old_run = (char *) s;
	while (runner != NULL && *runner != '\0')
	{
		if (old_run + 1 < runner)
			result++;
		old_run = runner;
		runner = ft_strchr(runner + 1, c);
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cw;
	size_t	i;
	char	*next_c;
	char	*curr_c;

	i = 0;
	if (c == '\0')
	{
		result = ft_calloc(2, sizeof(char *));
		result[0] = ft_strdup(s);
		return (result);
	}
	cw = count_words(s, c);
	result = ft_calloc(cw + 1, sizeof(char *));
	curr_c = ft_strchr(s, c);
	if (*s == '\0')
		return (result);
	next_c = ft_strchr(s + 1, c);
	while (i < cw)
	{
		if (curr_c + 1 < next_c)
		{
			result[i] = ft_substr(curr_c + 1, 0, (next_c - curr_c - 1));
			i++;
		}
		curr_c = next_c;
		if (next_c != NULL)
			next_c = ft_strchr(next_c + 1, c);
	}
	return (result);
}

#include <stdio.h>
int main(void)
{
	char **out;
	int i;
    char *input = "1238jdjk";
	char c = 'x';

	printf("words: %d\n", count_words(input, c));
	out = ft_split(input, c);
	i = 0;
	while (out[i])
	{
		printf("%d : \"%s\"\n", i, out[i]);
		i++;
	}
	return (0);
}
