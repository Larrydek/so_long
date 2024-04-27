/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:44:30 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 22:56:22 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && (s1[i] && s2[i]))
		i++;
	return (us1[i] - us2[i]);
}

// int main()
// {
//     printf("ft_strncmp: %d\n", ft_strncmp("test\200", "test\0", 6));
//     printf("strncmp: %d", strncmp("test\200", "test\0", 6));
//     printf("\nNUMERITO:\71");
//     return (0);
// }