#include "so_long.h"

void		ft_new_sprite(char *relative_path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, relative_path,  &img->img_width, &img->img_height);
	if (img->img == NULL)
		printf("SALTO ERROR!!!!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
									&img->endian);
}

int	main(void)
{
	t_image	*img;
	char *map_path;

	map_path = "map.ber";

	img = (t_image *)malloc(sizeof(t_image));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	img->img_width = 1920;
	img->img_height = 1080;
	
	ft_printf("ABAJO DE SAVE MAP\n");
	save_map(map_path, img);
	ft_put_map(img);
	ft_put_object(img);
	ft_put_pj(img);
	mlx_loop(img->mlx);
	return (0);
}
