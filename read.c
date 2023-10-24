#include "so_long.h"

int	y_axis(char *path)
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
	close(fd);
	return (y);
}

void	save_map(char *path, t_image *img)
{
	int i;
	int fd;
	int y;

	i = 0;
	fd = open(path, O_RDONLY);
	y = y_axis(path);

	img->map = (char **)malloc(y * sizeof(char *));

	while (i < y)
	{
	   img->map[i] = get_next_line(fd);
	   ft_printf("%s\n", img->map[i]);
	   i++;
	}
}
