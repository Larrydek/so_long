/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:26:21 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 23:12:16 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	i = 0;
	len_dst = ft_strlen(dst);
	while ((len_dst + i + 1) < dstsize && (i < ft_strlen(src)))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	if (dstsize < len_dst)
		return (ft_strlen(src) + dstsize);
	return (len_dst + ft_strlen(src));
}
