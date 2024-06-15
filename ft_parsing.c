/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:20:16 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:23:08 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_name(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (0);
	if (str[size - 4] == '.' && str[size - 3] == 'b'
		&& str[size - 2] == 'e' && str[size - 1] == 'r')
		return (1);
	return (0);
}

char	**map_it(char *file)
{
	int		fd;
	char	**map;
	char	*temp;
	char	*join;

	temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), exit(2), NULL);
	join = ft_strdup("");
	temp = get_next_line(fd);
	if (!temp)
		(ft_puterror("Error map!\n"), close(fd));
	while (temp)
	{
		join = ft_strjoinn(join, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close (fd);
	if (check_double_lines(join))
		return (free(join), NULL);
	map = ft_split(join, '\n');
	free(join);
	return (map);
}

int	check_double_lines(char *str)
{
	if (!str)
		return (ft_puterror(MAP_ERR), 1);
	if (str[ft_strlen(str) - 1] == '\n')
		return (1);
	while (*str)
	{
		if (*str == '\n' && *str == *(str + 1))
			return (1);
		str++;
	}
	return (0);
}

void	free_map(char **map)
{
	char	**tmp;

	tmp = map;
	if (!map || !(*map))
		return ;
	while (*map)
	{
		free(*map);
		(map)++;
	}
	map = tmp;
	free(map);
}

char	**ft_parsing(int ac, char **av)
{
	char	**map;

	if (ac != 2 || !check_file_name(av[1]))
		ft_puterror(EXT_ERR);
	map = map_it(av[1]);
	if (!map)
		ft_puterror(MAP_ERR);
	if (!check_map(map))
	{
		free_map(map);
		exit (1);
	}
	return (map);
}
