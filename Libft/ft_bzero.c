/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:05 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 17:16:52 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[15] = "palabra";
	printf("%s", ft_bzero(str, 4));
	return (0);
}*/