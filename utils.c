/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:55:33 by jde-clee          #+#    #+#             */
/*   Updated: 2023/11/17 06:11:26 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix, t_image *img)
{
	int	i;

	i = 0;
	while (i < img->y_len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_struct(t_image *img)
{
	if (!img)
		return ;
	if (img->y_len != -1 || img->x_len != -1)
		free_matrix(img->map, img);
	free(img);
}

int	free_and_close(t_image *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_struct(img);
	exit(0);
}

int	ft_strmatch(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	len_needle;

	i = 0;
	j = 0;
	len_needle = ft_strlen(needle);
	if (!needle || !haystack)
		return (0);
	while (haystack[i] != 0)
	{
		j = 0;
		i++;
		while (haystack[i] == needle[j])
		{
			j++;
			i++;
			if (j == len_needle && !haystack[i])
				return (1);
		}
	}
	return (0);
}
