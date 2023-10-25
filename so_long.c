#include "so_long.h"

void		ft_new_sprite(char *relative_path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, relative_path,  &img->img_width, &img->img_height);
	if (img->img == NULL)
		printf("SALTO ERROR!!!!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
									&img->endian);
}

int	key_hook(int keycode, t_image *img)
{
	if (keycode == 53)
	{
		mlx_clear_window(img->mlx, img->mlx_win);
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	ft_moves(keycode, img);
	return (0);
}

int	ft_so_long(void)
{
	t_image	*img;
	char *map_path;

	img = (t_image *)malloc(sizeof(t_image));
	map_path = "map.ber";

	ft_save_map(img, map_path);
	
	if (!ft_check_map(img, map_path))
		return (0);
	
	img->battery = 0;
	img->mlx = mlx_init();
	img->img_width = img->x_len * 50;
	img->img_height = img->y_len * 50;
	img->mlx_win = mlx_new_window(img->mlx, img->img_width, img->img_height, "Hello world!");
	
	ft_put_map(img);
	ft_put_object(img);
	ft_put_pj(img);

	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
	return (0);
}

int	main(void)
{
	ft_so_long();
	return(0);
}
