/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:15:54 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 20:18:18 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*cast_src;

	i = 0;
	result = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (!src && !dst)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			result[i] = cast_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			result[i] = cast_src[i];
	}
	return (dst);
}
// int main()
// {
//     int len;
//     //char dst[42] = "Rosario";
//     char src[42] = "Paraná";
//     char src2[42] = "Paraná";
//     len = 9;

//     printf("%s\n", memmove(src + 3, src, len));
//     printf("%s", ft_memmove(src2 + 3, src2, len));
//     return (0);
// }