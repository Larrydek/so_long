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
}				t_image;

void    ft_new_sprite(char *relative_path, t_image *img);
int		y_axis(char *path);
void	save_map(char *path, t_image *img);
void	ft_put_map(t_image *img);
void	ft_put_object(t_image *img);
void	ft_put_pj(t_image *img);

#endif