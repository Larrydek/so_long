/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:56:40 by jde-clee          #+#    #+#             */
/*   Updated: 2024/04/27 20:58:42 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_image *img, char *map_path)
{
	if (!img->map)
		return (0);
	img->y_len = ft_y_axis(map_path);
	img->x_len = ft_x_axis(img);
	if ((img->y_len < 2) || (img->x_len < 2))
		return (0);
	printf("CHECK_WALL X: %i\n", ft_check_wall_x(img));
	printf("CHECK_WALL Y: %i\n", ft_check_wall_y(img));
	if (ft_check_letters(img) && ft_check_wall_x(img)
		&& ft_check_wall_y(img) && ft_topology_check(map_path))
		return (1);
	printf("ERROR, EL MAPA FALLÓ\n");
	return (0);
}

int	ft_check_wall_x(t_image *img)
{
	int	i;

	i = 0;
	while (i < img->x_len)
	{
		if (img->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < img->x_len)
	{
		if (img->map[img->y_len - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall_y(t_image *img)
{
	int	i;

	i = 0;
	while (i < img->y_len)
	{
		if (img->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < img->y_len)
	{
		if (img->map[i][img->x_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_letters(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < img->y_len - 1)
	{
		while (j < img->x_len - 1)
		{
			if (ft_strchr(img->map[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	printf("CHECK LETTERS OK\n");
	return (1);
}
