/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:54:15 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 20:19:52 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *array, int c, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)array;
	while (i < len)
	{
		result[i] = c;
		i++;
	}
	return (result);
}

// int main()
// {
//     char array[18] = "computadora";
//     char arr_test[18] = "computadora";
//     printf("%s\n", "C memset:");
//     printf("%s\n", memset(array, 'i', 18));

//     printf("%s\n", "My memset:");
//     printf("%s", ft_memset(arr_test, 'i', 18));
//     return (0);
// }