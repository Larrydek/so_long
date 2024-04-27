/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:59 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 20:04:00 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*cast_src;

	i = 0;
	result = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		result[i] = cast_src[i];
		i++;
	}
	return (dst);
}

// int main()
// {
//     int n;
//     char dst[42];
//     char src[42] = "Palabritas";
//     n = 5;

//     printf("%s\n", memcpy(dst, src, n));
//     printf("%s", ft_memcpy(dst, src, n));
//     return (0);
// }