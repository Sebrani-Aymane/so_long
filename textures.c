/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:58:06 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:32:51 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_images( t_game *game)
{
	write(1, "Error in xpm files\n", 19);
	free_map(game->map);
	free(game->images);
	exit(1);
}

t_images	*set_images(t_game *game)
{
	t_images	*images;
	int			size;

	size = 64;
	images = malloc(sizeof(t_images));
	if (images == NULL)
		return (free_map(game->map), NULL);
	images ->wall = mlx_xpm_file_to_image(game->mlx, \
		"./maps/WAAAALL.xpm", &size, &size);
	images ->space = mlx_xpm_file_to_image(game->mlx, \
		"./maps/ba4.xpm", &size, &size);
	images ->player = mlx_xpm_file_to_image(game->mlx, \
		"./maps/22.xpm", &size, &size);
	images ->collect = mlx_xpm_file_to_image(game->mlx, \
	"./maps/Pickels.xpm", &size, &size);
	images -> exit = mlx_xpm_file_to_image(game->mlx, \
	"./maps/exit.xpm", &size, &size);
	if (!images->collect || !images->exit || !images->player
		|| !images->space || !images->wall)
		clear_images(game);
	return (images);
}

void	place_image(char tile, int x, int y, t_game *game)
{
	int	tmp;

	tmp = 64;
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->images->space, tmp * x, tmp * y);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->images->wall, tmp * x, tmp * y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->images->player, tmp * x, tmp * y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->images->collect, tmp * x, tmp * y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->images->exit, tmp * x, tmp * y);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->images->space, tmp * x, tmp * y);
}

int	ft_image(char **map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			place_image(map[j][i], i, j, game);
			i++;
		}
		j++;
	}
	return (0);
}

int	clooose(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit (1);
}
