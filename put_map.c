#include "so_long.h"

void	ft_put_map(t_image *img)
{
	char	*floor = "sprites/lab_floor.xpm";
    char    *column = "sprites/column.xpm";
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < img->y_len)
    {
        x = 0;
        while (x < img->x_len)
        {
            if (img->map[y][x] == '1')
                ft_new_sprite(column, img);
            else
                ft_new_sprite(floor, img);
	        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, x * 50, y * 50);
            x++;
        }
        y++;
    }
}

void	ft_put_object(t_image *img)
{
	char	*object = "sprites/battery.xpm";
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < img->y_len)
    {
        x = 0;
        while (x < img->x_len)
        {
            if (img->map[y][x] == 'C')
            {
                img->battery += 1;
                ft_new_sprite(object, img);
	            mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}

void	ft_put_pj(t_image *img)
{
	char	*object = "sprites/tesla_front_50x50.xpm";
    int x;
    int y;

    y = 0;
    while (y < img->y_len)
    {
        x = 0;
        while (x < img->x_len)
        {
            if (img->map[y][x] == 'P')
            {
                img->x_pos = x;
                img->y_pos = y;
                img->map[img->y_pos][img->x_pos] = 'P';
                ft_new_sprite(object, img);
	            mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}

void	ft_put_exit(t_image *img)
{
	char	*object = "sprites/Delorean.xpm";
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < img->y_len)
    {
        x = 0;
        while (x < img->x_len)
        {
            if (img->map[y][x] == 'E')
            {
                ft_new_sprite(object, img);
	            mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}
