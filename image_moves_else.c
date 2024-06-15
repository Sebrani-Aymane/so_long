/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_moves_else.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:51:28 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:45:36 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror(char *s)
{
	write(1, "Error\n", 6);
	if (s)
		write(2, s, ft_strlenn(s));
	exit(1);
}

int	cal_collect(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count ++;
			i++;
		}
		j++;
	}
	return (count);
}

void	destory_t_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->collect);
	mlx_destroy_image(game->mlx, game->images->wall);
	mlx_destroy_image(game->mlx, game->images->space);
	mlx_destroy_image(game->mlx, game->images->player);
	mlx_destroy_image(game->mlx, game->images->exit);
	exit (1);
}

int	moves(int moves, t_game *game)
{
	if (moves == 13 || moves == 126)
		move_up(game);
	if (moves == 1 || moves == 125)
		move_down(game);
	if (moves == 0 || moves == 123)
		move_left(game);
	if (moves == 2 || moves == 124)
		move_right(game);
	if (moves == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit (1);
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	ft_image(game->map, game);
	return (1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}
