/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:51:41 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:39:19 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libc.h>
# include "get_next_line.h"
# include <mlx.h>
# include <errno.h>

# define MAP_ERR "Error map!\n"
# define EXT_ERR "Error in map file name\n"
# define WALL_ERR "error in first line\n"
# define IMG_ERR "error with the img\n"

typedef struct images
{
	void	*wall;
	void	*space;
	void	*player;
	void	*collect;
	void	*exit;
}	t_images;

typedef struct c_cords
{
	int	x;
	int	y;
}	t_cords;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			moves;
	t_cords		player_pos;
	t_cords		map_data;
	t_images	*images;
	char		**map;
}	t_game;
typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int			check_map(char **map);
void		free_map(char **map);
void		ft_putnbr(int nb);
int			check_accur(char *str, char *check);
int			check_count(char **map);
int			check_double_lines(char *str);
t_cords		get_pos_p(char **map);
int			check_wall(char *line);
t_images	*set_images(t_game *game);
int			count_characters(char	**map, char target);
char		*ft_strdup(const char *s1);
int			ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_puterror(char *s);
char		**ft_parsing(int ac, char **av);
int			moves(int moves, t_game *game);
int			ft_image(char **map, t_game *game);
int			check_path(char **map);
void		free_map(char **map);
t_cords		map_height_width(char **map);
int			move_up(t_game *game);
int			move_right(t_game *game);
int			move_down(t_game *game);
int			cal_collect(char **map);
int			move_left(t_game *game);
int			clooose(t_game *game);
void		ft_putstr(char *str);
#endif