/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:40:32 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:35:03 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(char **map)
{
	char	**dup_map;
	int		count_db;
	int		i;

	i = 0;
	count_db = 0;
	while (map[count_db])
		count_db++;
	dup_map = malloc(sizeof(char *) * (count_db + 1));
	if (!dup_map)
		return (NULL);
	while (map[i])
	{
		dup_map[i] = ft_strdup(map[i]);
		if (!dup_map[i])
		{
			free_map(dup_map);
			exit(1);
		}
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

void	flood_f(char **map, int y, int x)
{
	if (x < 0 || y < 0 || map[y][x] == '1'
		|| map[y][x] == 'X' || map[y][x] == 'T')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'T';
		return ;
	}
	map[y][x] = 'X';
	flood_f(map, y - 1, x);
	flood_f(map, y + 1, x);
	flood_f(map, y, x + 1);
	flood_f(map, y, x - 1);
}

int	check_path(char **map)
{
	char	**cp_map;
	t_cords	cords;
	int		c;
	int		p;
	int		e;

	c = 0;
	p = 0;
	e = 0;
	cp_map = dup_map(map);
	cords = get_pos_p(cp_map);
	flood_f(cp_map, cords.y, cords.x);
	c = count_characters(cp_map, 'C');
	p = count_characters(cp_map, 'P');
	e = count_characters(cp_map, 'T');
	free_map (cp_map);
	if (c != 0 || p != 0 || e != 1)
		return (0);
	else
		return (1);
}

int	check_map(char **map)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlenn(map[0]);
	if (!check_wall(map[0]))
		ft_puterror(MAP_ERR);
	while (map[i])
	{
		if (!(check_accur(map[i], "10PEC")))
			return (ft_putstr("incorrect charrrrrrs\n"), 0);
		if (map[i][0] != '1' || map[i][ft_strlenn(map[i]) - 1] != '1')
			return (ft_putstr("error in borders\n"), 0);
		if (size != (int)ft_strlenn(map[i]))
			return (ft_putstr("size is not correct\n"), 0);
		i++;
	}
	if (!check_count(map))
		return (ft_putstr("error in count chars\n"), 0);
	if (!check_wall(map[i - 1]))
		return (ft_putstr("error in last line\n"), 0);
	if (!check_path(map))
		return (ft_putstr("INVALID PATH\n"), 0);
	return (1);
}
