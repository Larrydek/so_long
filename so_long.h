/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:55:53 by jde-clee          #+#    #+#             */
/*   Updated: 2024/04/27 22:33:30 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include "Libft/libft.h"

# define FLOOD_FILL_CHARS "CE0"
# define CHECK_FILL_CHARS "CE"
# define MAP_CHARS "CEP10\n"

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		nmr_columnas;
	int		x_len;
	int		y_len;
	int		x_pos;
	int		y_pos;
	int		battery;
	int		pj;
	int		exit;
	int		count_moves;
}				t_image;

void	ft_new_sprite(char *relative_path, t_image *img);
int		ft_y_axis(char *path);
int		ft_x_axis(t_image *img);
void	ft_save_map(t_image *img, char *path);
void	ft_put_map(t_image *img);

int		ft_check_map(t_image *img, char *map_path);
int		ft_check_letters(t_image *img);
int		ft_check_wall_x(t_image *img);
int		ft_check_wall_y(t_image *img);
int		ft_topology_check(char *map_path);
t_image	*ft_copy_map(char *map_path);
void	ft_check_pj_pos(t_image *copy_img);
void	ft_flood_fill(t_image *copy_img, int y, int x);
int		check_fill(t_image *copy_img);

void	ft_put_object(t_image *img);
void	ft_put_pj(t_image *img);
void	ft_put_exit(t_image *img);
void	ft_show_things(t_image *img);

void	ft_moves(int key, t_image *img);
void	ft_move_down(t_image *img);
void	ft_move_up(t_image *img);
void	ft_move_left(t_image *img);
void	ft_move_right(t_image *img);
void	ft_collector(t_image *img);
int		ft_so_long(char *argv);
void	free_matrix(char **matrix, t_image *img);
void	free_struct(t_image *img);
int		free_and_close(t_image *img);
int		ft_strmatch(char *haystack, char *needle);
#endif