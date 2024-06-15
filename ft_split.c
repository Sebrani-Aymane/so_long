/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:20:31 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 15:50:27 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

static size_t	count_word(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static	int	norminet_split(char *s, int *i, char c, int *size)
{
	(*size) = 0;
	while (s[(*i)] == c && s[(*i)])
		(*i)++;
	while (s[(*i)] != c && s[(*i)])
	{
		(*size)++;
		(*i)++;
	}
	return (2001);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	size_t	l;
	int		size;

	if (!s)
		return (NULL);
	l = 0;
	i = 0;
	dst = (char **)ft_callocc((count_word(s, c) + 1), sizeof(char *));
	if (!dst)
		return (NULL);
	while (l < count_word(s, c) && s[i])
	{
		norminet_split((char *)s, &i, c, &size);
		if (size > 0)
		{
			dst[l] = ft_substr(s, i - size, size);
			if (dst[l] == NULL)
				return (ft_free(dst), NULL);
			l++;
		}
	}
	dst[l] = ((void *)0);
	return (dst);
}
