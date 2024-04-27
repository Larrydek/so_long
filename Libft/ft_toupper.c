/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:06 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 23:05:36 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_toupper(int c)
{
	int	upper;

	upper = c;
	if (upper > 96 && upper < 123)
		upper = upper - 32;
	return (upper);
}

// int main()
// {
//     int c;
//     c = 97;
//     printf("%d", ft_toupper(c));
//     printf("%d", toupper(c));
//     return (0);
// }
