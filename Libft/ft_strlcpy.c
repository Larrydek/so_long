/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:04:34 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 22:43:05 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// int main()
// {
//     char dst[90] = "";
//     char ft_dst[90] = "";
//     char *src = " DE SANTA FE";
//     char *ft_src = " DE SANTA FE";

//     printf("STRLCPY: %zu", strlcpy(dst, "aasdjj;s;sa", 100));
//     printf("\n");
//     printf("dst: %s", dst);
//     printf("\n");
//     printf("src: %s", src);
//     printf("\n");
//     printf("\n");
//     printf("FT_STRLCPY: %zu", ft_strlcpy(ft_dst, "aasdjj;s;sa", 100));
//     printf("\n");
//     printf("ft_dst: %s", ft_dst);
//     printf("\n");
//     printf("ft_src: %s", ft_src);

//     return (0);
// }
