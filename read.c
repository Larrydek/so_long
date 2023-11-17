/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:55:57 by jde-clee          #+#    #+#             */
/*   Updated: 2023/11/17 05:38:02 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_y_axis(char *path)
{
	int		y;
	int		bytes;
	int		fd;
	char	buffer[1];

	y = 1;
	bytes = 1;
	fd = open(path, O_RDONLY);
	bytes = read(fd, buffer, 1);
	if (bytes == 0)
		return (-1);
	while (bytes != 0)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			y++;
	}
	if (buffer[0] == '\n')
		return (-1);
	close(fd);
	return (y);
}

//hacer una funcion para x_len//
int	ft_x_axis(t_image *img)
{
	int	i;
	int	x_len;

	i = 0;
	if ((!img->map) || (img->y_len < 2))
		return (-1);
	x_len = ft_strlen(img->map[0]);
	img->x_len = x_len;
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
	int	i;
	int	fd;
	int	y;

	i = 0;
	fd = open(path, O_RDONLY);
	y = ft_y_axis(path);
	img->y_len = y;
	if (img->y_len > 0)
	{
		img->map = (char **)malloc(y * sizeof(char *));
		printf("ft_save_map %p\n", img->map);
		if (!img->map)
			return ;
	}
	else
		return ;
	while (i < y - 1)
	{
		img->map[i] = get_next_line(fd);
		img->map[i][ft_strlen(img->map[i]) - 1] = '\0';
		i++;
	}
	if (img->y_len != -1)
		img->map[i] = get_next_line(fd);
}
