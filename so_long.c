#include "so_long.h"

void		ft_new_sprite(char *relative_path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, relative_path,  &img->img_width, &img->img_height);
	if (img->img == NULL)
		printf("SALTO ERROR EN MLX!!!!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
									&img->endian);
}

int	key_hook(int keycode, t_image *img)
{
	if (keycode == 53)
	{
		mlx_clear_window(img->mlx, img->mlx_win);
		mlx_destroy_window(img->mlx, img->mlx_win);
		free_struct(img);
		exit(0);
	}
	ft_moves(keycode, img);
	return (0);
}

void	ft_show_things(t_image *img)
{
	img->mlx = mlx_init();
	img->img_width = img->x_len * 50;
	img->img_height = img->y_len * 50;
	img->mlx_win = mlx_new_window(img->mlx, img->img_width, img->img_height, "Hello world!");
	
	ft_put_map(img);
	ft_put_object(img);
	ft_put_pj(img);

	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	ft_so_long(char *argv)
{
	t_image	*img;
	char *map_path;

	printf("HASTA ACÁ LLEGAMO\n");
	map_path = argv;
	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (0);
	img->battery = 0;
	img->pj = 0;
	img->exit = 0;
	img->count_moves = 0;
	img->y_len = 0;
	img->x_len = 0;
	ft_save_map(img, map_path);
	printf("*img %p\n", img);
	if (!ft_check_map(img, map_path))
		return (free_struct(img), 0);
	else
		ft_show_things(img);
	return (0);
}

int	main(int argc, char **argv)
{
	atexit(leaks);

	if (argc != 2)
	{
		ft_printf("HAY ALGO MAL, TIENE QUE HABER 2 ARGUMENTOIS");
		return (0);
	}
	ft_so_long(argv[1]);
	return(0);
}
