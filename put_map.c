/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:56:15 by jde-clee          #+#    #+#             */
/*   Updated: 2023/11/17 05:24:48 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_map(t_image *img)
{
	char	*floor;
	char	*column;
	int		x;
	int		y;

	floor = "sprites/lab_floor.xpm";
	column = "sprites/column.xpm";
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
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_put_object(t_image *img)
{
	char	*object;
	int		x;
	int		y;

	object = "sprites/battery.xpm";
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
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_pj(t_image *img)
{
	char	*object;
	int		x;
	int		y;

	object = "sprites/tesla_front_50x50.xpm";
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
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_exit(t_image *img)
{
	char	*object;
	int		x;
	int		y;

	object = "sprites/Delorean.xpm";
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
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	ft_collector(t_image *img)
{
	if (img->map[img->y_pos][img->x_pos] == 'C')
	{
		ft_new_sprite("sprites/lab_floor.xpm", img);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, img->x_pos * 50, img->y_pos * 50);
		ft_new_sprite("sprites/tesla_front_50x50.xpm", img);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, img->x_pos * 50, img->y_pos * 50);
		img->battery -= 1;
		img->map[img->y_pos][img->x_pos] = '0';
		if (img->battery == 0)
			ft_put_exit(img);
	}
}
