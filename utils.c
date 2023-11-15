#include "so_long.h"

void    free_matrix(char **matrix, t_image *img)
{
	int i;

	i = 0;
	//printf("Y_LEN!!!:: %i \n", img->y_len);
	while (i < img->y_len)
	{
		//printf("[%i]: %s\n", i, matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void free_struct(t_image *img)
{
	if (!img)
		return;
	if(img->y_len != -1 || img->x_len != -1)
		free_matrix(img->map, img);
	free(img);
}

int	free_and_close(t_image *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_struct(img);
	exit(0);
}