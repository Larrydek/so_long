#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./printf/ft_printf.h"

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
#endif