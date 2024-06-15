/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:58:37 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 22:23:09 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_accur(char *str, char *check)
{
	while (*str)
		if (!ft_strchrr(check, *(str++)))
			return (0);
	return (1);
}

int	count_characters(char	**map, char target)
{
	int	count;
	int	i;
	int	j;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == target)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	check_count(char	**map)
{
	int	c;
	int	p;
	int	e;

	c = count_characters(map, 'C');
	p = count_characters(map, 'P');
	e = count_characters(map, 'E');
	if (c >= 1 && p == 1 && e == 1)
		return (1);
	else
		return (0);
}

t_cords	get_pos_p(char **map)
{
	t_cords	player_cords;
	int		y;
	int		x;

	player_cords.x = 0;
	player_cords.y = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player_cords.x = x;
				player_cords.y = y;
				return (player_cords);
			}
			x++;
		}
		y++;
	}
	return (player_cords);
}

int	check_wall(char *line)
{
	while (*line)
		if (!ft_strchrr("1",*(line++)))
			return (0);
	return (1);
}
