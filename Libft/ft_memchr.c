/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:12 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 19:59:55 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (us[i] != uc && i < n - 1)
		i++;
	if (us[i] == uc)
		return (us + i);
	return (NULL);
}

// int main()
// {
//     printf("ft_memchr: %s\n", ft_memchr("palabra", 'b', 1));
//     printf("memchr: %s", memchr("palabra", 'b', 1));
//     return (0);
// }