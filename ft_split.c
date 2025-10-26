/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:15:06 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/26 16:58:18 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	result;
	char	*runner;
	char	*old_run;

	result = 0;
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

// write one that does ignore multiple occorunances of c
char **ft_split(char const *s, char c)
{
	char	**result;
	size_t	cw;
	size_t	i;
	char	*next_c;
	char	*curr_c;

	i = 0;
	cw = count_words(s, c);
	result = ft_calloc(cw + 1, sizeof(char *));
	curr_c = ft_strchr(s, c);
	if (*s == '\0')
		return (result);
	next_c = ft_strchr(s + 1, c);
	while (curr_c != NULL)
	{
		if (curr_c + 1 < next_c)
		{
			result[i] = ft_substr(curr_c, 0, (next_c - curr_c));
			i++;
		}
		curr_c = next_c;
		if (next_c != NULL)
			next_c = ft_strchr(next_c + 1, c);
	}
	return (result);
}
