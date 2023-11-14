#include "so_long.h"

int		ft_y_axis(char *path)
{
	int y;
	int bytes;
	int fd;
	char buffer[1];

	y = 1;
	bytes = 1;

	fd = open(path, O_RDONLY);

	while (bytes != 0)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			y++;
	}
	if (buffer[0] == '\n')
		return (0);
	close(fd);
	return (y);
}
//hacer una funcion para x_len//
int		ft_x_axis(t_image *img)
{
	int i;
	int x_len;

	i = 0;
	x_len = ft_strlen(img->map[0]);
	printf("PRIMERA LINEA: %s\n", img->map[0]);
	printf("X_LEN X_AXIS: %i\n", x_len);
	if (img->y_len == 0)
		return (0);
	while (i < img->y_len)
	{
		if (x_len != (int)ft_strlen(img->map[i]))
			return (0);
		i++;
	}
	return (x_len);
}

void	ft_save_map(t_image *img, char *path)
{
	int i;
	int fd;
	int y;

	i = 0;
	fd = open(path, O_RDONLY);
	y = ft_y_axis(path);
	printf("DIO UNA VUELTITA POR ACA\n");

	img->map = (char **)malloc(y  * sizeof(char *));
		if (!img->map)
			return ;
	printf("ft_save_map %p\n", img->map);

	while (i < y - 1)
	{
		printf("LLEGo AL GNL !!!!!!!\n");
	   img->map[i] = get_next_line(fd);
	   img->map[i][ft_strlen(img->map[i]) - 1] = '\0';
	   ft_printf("[%i] %s ", i, img->map[i]);
	   ft_printf("----> len: %i\n", ft_strlen(img->map[i]));
	   i++;
	}
	img->map[i] = get_next_line(fd);
	ft_printf("[%i] %s ", i, img->map[i]);
	ft_printf("----> len: %i\n", ft_strlen(img->map[i]));
}
