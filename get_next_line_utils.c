/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:18:51 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 22:18:02 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	res = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	free(s1);
	return (res);
}

char	*ft_strchrr(char *string, int c )
{
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)string;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzeroo(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_callocc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzeroo(res, size * count);
	return (res);
}
