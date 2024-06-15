/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:17:59 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:46:32 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cords	map_height_width(char **map)
{
	int		i;
	int		j;
	t_cords	map_data;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		j++;
	}
	map_data.x = i;
	map_data.y = j;
	return (map_data);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = malloc(j + 1);
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > (unsigned int)ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return ((void *)0);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
