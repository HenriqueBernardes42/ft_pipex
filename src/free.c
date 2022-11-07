/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:22:46 by hbernard          #+#    #+#             */
/*   Updated: 2022/11/06 22:44:22 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_word_counter(char const *s, char c);
char	**split_it(char **split, char const *s, char c, size_t words);
char	**pipex_split(char const *s, char c);

size_t	gen_strlen(char const *str, char delim)
{
	size_t	i;

	i = 0;
	while (str[i] != delim && str[i])
		i++;
	return (i + 1);
}

size_t	ft_word_counter(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
			}
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

char	**split_it(char **split, char const *s, char c, size_t words)
{
	size_t		i;
	size_t		j;
	int			len;

	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'')
			len = gen_strlen(&s[++i], '\'');
		else
			len = gen_strlen(&s[i], c);
		split[j] = ft_calloc(sizeof(char), len);
		if (!split[j])
			return (NULL);
		else
			ft_strlcpy(split[j], &s[i], len);
		i += len;
	}
	return (split);
}

char	**pipex_split(char const *s, char c)
{
	size_t	words;
	char	**split;

	words = ft_word_counter(s, c);
	split = ft_calloc(sizeof(char *), (words + 1));
	if (!split)
		return (NULL);
	split_it(split, s, c, words);
	return (split);
}
