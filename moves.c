#include "so_long.h"

void    ft_moves(int key, t_image *img)
{
	if (key == 13 | key == 0 | key == 1 | key == 2)
	{
		ft_new_sprite("sprites/lab_floor.xpm", img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
		if (key == 13)
			ft_move_down(img);
		if (key == 0)
			ft_move_left(img);
		if (key == 1)
			ft_move_up(img);
		if (key == 2)
			ft_move_right(img);
	}
	ft_collector(img);
	if (img->map[img->y_pos][img->x_pos] == 'E')
	{
		ft_printf("GANASTE CAMPEÓN");
		mlx_clear_window(img->mlx, img->mlx_win);
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
}

void	ft_collector(t_image *img)
{
	if (img->map[img->y_pos][img->x_pos] == 'C')
	{
		ft_new_sprite("sprites/lab_floor.xpm", img);
        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
		ft_new_sprite("sprites/tesla_front_50x50.xpm", img);
        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
		img->battery -= 1;
		img->map[img->y_pos][img->x_pos] = '0';
		if (img->battery == 0)
			ft_put_exit(img);
	}
}

void    ft_move_down(t_image *img)
{
	if (img->map[img->y_pos - 1][img->x_pos] != '1')
		img->y_pos -= 1;
	ft_new_sprite("sprites/tesla_front_50x50.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
}

void    ft_move_left( t_image *img)
{
	if (img->map[img->y_pos][img->x_pos - 1] != '1')
		img->x_pos -= 1;
	ft_new_sprite("sprites/tesla_left_50x50.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
}

void    ft_move_up(t_image *img)
{
	if (img->map[img->y_pos + 1][img->x_pos] != '1')
		img->y_pos += 1;
	ft_new_sprite("sprites/tesla_front_50x50.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
}

void    ft_move_right(t_image *img)
{
	if (img->map[img->y_pos][img->x_pos + 1] != '1')
		img->x_pos += 1;
	ft_new_sprite("sprites/tesla_right_50x50.xpm", img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
}