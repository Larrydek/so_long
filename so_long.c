/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:55:48 by jde-clee          #+#    #+#             */
/*   Updated: 2024/04/28 01:54:30 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_sprite(char *relative_path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, relative_path,
			&img->img_width, &img->img_height);
	if (img->img == NULL)
		ft_printf("ERROR EN MLX!!!!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	key_hook(int keycode, t_image *img)
{
	if (keycode == 53)
		free_and_close(img);
	ft_moves(keycode, img);
	return (0);
}

void	ft_show_things(t_image *img)
{
	img->mlx = mlx_init();
	img->img_width = img->x_len * 50;
	img->img_height = img->y_len * 50;
	img->mlx_win = mlx_new_window(img->mlx, img->img_width, img->img_height,
			"JUEGUE MAESTRO, JUEGUE");
	ft_put_map(img);
	ft_put_object(img);
	ft_put_pj(img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, free_and_close, img);
	mlx_loop(img->mlx);
}

int	ft_so_long(char *argv)
{
	t_image	*img;
	char	*map_path;

	map_path = argv;
	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (0);
	img->battery = 0;
	img->pj = 0;
	img->exit = 0;
	img->count_moves = 0;
	img->y_len = 0;
	img->x_len = 0;
	if ((open(map_path, O_RDONLY)) == -1)
		return (free(img), ft_printf("ERROR: NO HAY MAPA/NO PUEDE ABRIRSE\n"));
	ft_save_map(img, map_path);
	if (!ft_check_map(img, map_path))
	{
		ft_printf("ERROR: EL MAPA NO CUMPLE CON LOS REQUISITOS\n");
		return (free_struct(img), 0);
	}
	else
		ft_show_things(img);
	return (0);
}
/*
void	leaks(void)
{
	system("leaks -q so_long");
}
*/

int	main(int argc, char **argv)
{
	char	*map_format;

	map_format = ".ber";
	if (argc != 2)
	{
		ft_printf("ERROR: TIENE QUE HABER 2 ARGUMENTOS\n");
		return (0);
	}
	if (ft_strmatch(argv[1], ".ber") == 0)
	{
		ft_printf("ERROR: LA EXTENSIÓN DEL MAPA NO ES .BER\n");
		return (0);
	}
	ft_so_long(argv[1]);
	return (0);
}
