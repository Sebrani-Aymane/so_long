/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:05:24 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 22:55:50 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;

	map = ft_parsing(ac, av);
	game.player_pos = get_pos_p(map);
	game.map = map;
	game.map_data = map_height_width(map);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(1, "Error initializing MLX\n", 24), 1);
	game.moves = 0;
	game.mlx_win = mlx_new_window(game.mlx, game.map_data.x * 64, \
		game.map_data.y * 64, "Rick's Morty");
	if (!game.mlx_win)
		return (write(1, "Error with thw window\n", 23), 1);
	game.images = set_images(&game);
	ft_image(map, &game);
	mlx_hook(game.mlx_win, 17, 0, clooose, &game);
	mlx_hook(game.mlx_win, 2, 0, moves, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
