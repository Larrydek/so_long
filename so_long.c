#include "so_long.h"

void		ft_new_sprite(char *relative_path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, relative_path,  &img->img_width, &img->img_height);
	if (img->img == NULL)
		printf("SALTO ERROR!!!!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
									&img->endian);
}

/* void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 4));
	*(unsigned int*)dst = color;
} */

void	main(void)
{
	t_image	*img;
	int	fd;
	char	*relative_path = "./sprites/lab_floor.xpm";
	img = NULL;
	fd = open(relative_path, O_RDONLY);
	printf("%d\n", fd);
	close(fd);

	img = (t_image *)malloc(sizeof(t_image));
	printf("ERROR ACA!!!!!");
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	img->img_width = 1920;
	img->img_height = 1080;
	
	ft_new_sprite(relative_path, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 50, 50);
	mlx_loop(img->mlx);
}
