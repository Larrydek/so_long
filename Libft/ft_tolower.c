/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:53:29 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 23:04:21 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_tolower(int c)
{
	int	lower;

	lower = c;
	if (lower > 64 && lower < 91)
		lower = lower + 32;
	return (lower);
}

// int main()
// {
//     int c;
//     c = 97;
//     printf("%d", ft_tolower(c));
//     printf("%d", tolower(c));
//     return (0);
// }
