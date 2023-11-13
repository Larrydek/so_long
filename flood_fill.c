#include "so_long.h"

int	ft_topology_check(char *map_path)
{
	t_image *copy_img;

	printf("AS:;NDA;DSMN;ASDMN\n");
	copy_img = ft_copy_map(map_path);
	if (!copy_img)
		return (0);
	printf("AS:;NDA;DSMN;ASDMN\n");
	ft_check_pj_pos(copy_img);
	if (copy_img->battery == 0 | copy_img->pj != 1 | copy_img->exit != 1)
	{
		ft_printf("Error: 0 Baterías o PJ o EXIT\n");
		ft_printf("BATERÍAS: %i\n", copy_img->battery);
		ft_printf("PJ: %i\n", copy_img->pj);
		ft_printf("EXIT: %i\n", copy_img->exit);
		printf("AS:;NDA;DSMN;ASDMN\n");
		return (free_struct(copy_img), 0);
	}
	ft_flood_fill(copy_img, copy_img->y_pos, copy_img->x_pos);
	printf("ft_copy_map %p\n", copy_img);
	if (check_fill(copy_img))
		return (free_struct(copy_img), 1);
	else
		return (free_struct(copy_img), 0);
}

t_image *ft_copy_map(char *map_path)
{
	t_image	*copy_img;

	copy_img = (t_image *)malloc(sizeof(t_image));
	if (!copy_img)
		return (0);
	printf("ft_copy_map %p\n", copy_img);
	ft_save_map(copy_img, map_path);
	copy_img->y_len = ft_y_axis(map_path);
	copy_img->x_len = ft_x_axis(copy_img);
	copy_img->battery = 0;
	copy_img->pj = 0;
	copy_img->exit = 0;
	return (copy_img);
}

void	ft_check_pj_pos(t_image *copy_img)
{
	int x;
    int y;

	x = 0;
    y = 0;
    while (y < copy_img->y_len)
    {
        x = 0;
        while (x < copy_img->x_len)
        {
            if (copy_img->map[y][x] == 'P')
            {
                copy_img->x_pos = x;
                copy_img->y_pos = y;
                copy_img->pj += 1;
            }
			if (copy_img->map[y][x] == 'C')
				copy_img->battery += 1;
			if (copy_img->map[y][x] == 'E')
				copy_img->exit += 1;
            x++;
        }
        y++;
    }
}
void	ft_flood_fill(t_image *copy_img, int y, int x)
{
	if (FLOOD_FILL_CHARS(copy_img->map[y + 1][x]))
	{
		copy_img->map[y + 1][x] = 'P';
		ft_flood_fill(copy_img, y + 1, x);
	}
	if (FLOOD_FILL_CHARS(copy_img->map[y - 1][x]))
	{
		copy_img->map[y - 1][x] = 'P';

		ft_flood_fill(copy_img, y - 1, x);
	}
	if (FLOOD_FILL_CHARS(copy_img->map[y][x + 1]))
	{
		copy_img->map[y][x + 1] = 'P';
		ft_flood_fill(copy_img, y, x + 1);
	}
	if (FLOOD_FILL_CHARS(copy_img->map[y][x - 1]))
	{
		copy_img->map[y][x - 1] = 'P';
		ft_flood_fill(copy_img, y, x - 1);
	}
}

int check_fill(t_image *copy_img)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < copy_img->y_len)
	{
		x = 0;
		while (x < copy_img->x_len)
		{
			ft_printf("%c", copy_img->map[y][x]);
			if (FLOOD_FILL_CHARS(copy_img->map[y][x]) == 1)
			{
				ft_printf("NO SE CONECTA EL PJ, BATERIAS Y SALIDA\n");
				return (0);
			}
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("TODO BIEN PA\n");
	return (1);
}
