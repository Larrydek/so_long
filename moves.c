#include "so_long.h"

void    ft_moves(int key, t_image *img)
{
    ft_new_sprite("sprites/lab_floor.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);

    if (key == 13)
        img->y_pos -=1;
    if (key == 0)
        img->x_pos -=1;
    if (key == 1)
        img->y_pos +=1;
    if (key == 2)
        img->x_pos +=1;

    ft_new_sprite("sprites/tesla_front_50x50.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
}