#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include "Libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
    void	*mlx;
	void	*mlx_win;
	int		nmr_columnas;
	int		x_pos;
	int		y_pos;
	int		battery;
	int		x_len;
	int		y_len;
}				t_image;

void    ft_new_sprite(char *relative_path, t_image *img);
int		ft_y_axis(char *path);
void	ft_save_map(t_image *img, char *path);
void	ft_put_map(t_image *img);
int    ft_check_map(t_image *img, char *map_path);
int    ft_check_wall_x(t_image *img);
int    ft_check_wall_y(t_image *img);

void	ft_put_object(t_image *img);
void	ft_put_pj(t_image *img);
void	ft_put_exit(t_image *img);

void    ft_moves(int key, t_image *img);
void    ft_move_down(t_image *img);
void    ft_move_up(t_image *img);
void    ft_move_left(t_image *img);
void    ft_move_right(t_image *img);
void	ft_collector(t_image *img);
int		ft_so_long(void);

#endif