/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:34:34 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/03 19:58:06 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int n, const char format, int *len)
{
	if (n >= 16)
	{
		ft_hex(n / 16, format, len);
		ft_hex(n % 16, format, len);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0', len);
		else
		{
			if (format == 'x')
				ft_char((n - 10) + 'a', len);
			if (format == 'X')
				ft_char((n - 10) + 'A', len);
		}
	}
}

int	*ft_print_hex(unsigned int num, const char format, int *len)
{
	if (num == 0)
	{
		write(1, "0", 1);
		(*len)++;
	}
	else
		ft_hex(num, format, len);
	return (len);
}
