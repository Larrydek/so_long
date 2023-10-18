#include <mlx.h>
#include "./printf/ft_printf.h"
#include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct m_data {
	void	*mlx;
	void	*mlx_win;
	int		nmr_columnas;

} main_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	img;
	main_data gnrl;
	int	fd;
	char	*relative_path = "./sprites/tesla_front.xpm";

	fd = open(relative_path, O_RDONLY);
	printf("%d\n", fd);
	close(fd);
	
	gnrl.mlx = mlx_init();
	gnrl.mlx_win = mlx_new_window(gnrl.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_xpm_file_to_image(gnrl.mlx, relative_path,  &(img.img_width), &(img.img_height));

	if (img.img == NULL)
		return(printf("SALTO ERROR!!!!\n"));
	else
		printf("width: %i\n", img.img_width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(gnrl.mlx, gnrl.mlx_win, img.img, 50, 50);
	mlx_loop(gnrl.mlx);
}