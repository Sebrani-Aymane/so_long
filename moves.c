/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:17:21 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:46:57 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{
	{
		if (game->map[game->player_pos.y][game->player_pos.x + 1] != '1'
			&& game->map[game->player_pos.y][game->player_pos.x + 1] != 'E')
		{
			game->map[game->player_pos.y][game->player_pos.x] = '0';
			game->map[game->player_pos.y][game->player_pos.x + 1] = 'P';
			game->player_pos.x += 1;
		}
		else if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'E'
				&& !cal_collect(game->map))
			exit(0);
		game->moves++;
		write(1, "move : ", 7);
		ft_putnbr(game->moves);
		write(1, "\n", 1);
	}
	return (1);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_pos.y + 1][game->player_pos.x] != '1'
		&& game->map[game->player_pos.y + 1][game->player_pos.x] != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->map[game->player_pos.y + 1][game->player_pos.x] = 'P';
		game->player_pos.y += 1;
	}
	else if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'E'
			&& !cal_collect(game->map))
		exit (0);
	game->moves++;
	write(1, "move : ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

int	move_up(t_game *game)
{
	if (game->map[game->player_pos.y -1][game->player_pos.x] != '1'
		&& game->map[game->player_pos.y - 1][game->player_pos.x] != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->map[game->player_pos.y - 1][game->player_pos.x] = 'P';
		game->player_pos.y -= 1;
	}
	else if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'E'
		&& !cal_collect(game->map))
		exit (0);
	game->moves++;
	write(1, "move : ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

int	move_left(t_game *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x - 1] != '1'
		&& game->map[game->player_pos.y][game->player_pos.x - 1] != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->map[game->player_pos.y][game->player_pos.x - 1] = 'P';
		game->player_pos.x -= 1;
	}
	else if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'E'
		&& !cal_collect(game->map))
		exit(0);
	game->moves++;
	write(1, "move : ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}
