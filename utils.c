#include "so_long.h"

void    free_matrix(char **matrix, t_image *img)
{
	int i;

	i = 0;
	printf("%i Y_LEN!!!:::!::\n", img->y_len);
	while (i < img->y_len)
	{
		printf("[%i]: %s\n", i, matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void free_struct(t_image *img)
{
	if (!img)
		return;
	free_matrix(img->map, img);
	free(img);
}