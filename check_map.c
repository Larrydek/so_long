#include "so_long.h"

int     ft_check_map(t_image *img, char *map_path)
{
    img->x_len = ft_strlen(img->map[0]) - 1;
    img->y_len = ft_y_axis(map_path);

    ft_printf("CHECK WALL X: %i", ft_check_wall_x(img));
    ft_printf("CHECK WALL Y: %i", ft_check_wall_y(img));
    if (ft_check_wall_x(img) && ft_check_wall_y(img))
        return (1);
    return (0);
}

int    ft_check_wall_x(t_image *img)
{
    int i;

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

int     ft_check_wall_y(t_image *img)
{
    int i;

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

