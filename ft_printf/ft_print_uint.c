/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:36:01 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/03 19:58:38 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int n, int *len)
{
	if (n > 9)
		ft_print_uint(n / 10, len);
	if (n <= 9)
	{
		ft_char(n + '0', len);
		return ;
	}
	ft_char((n % 10) + '0', len);
}

int	*ft_print_uint(unsigned int num, int *len)
{
	ft_unsigned(num, len);
	if (num == 0)
		return (len);
	while (num > 0)
		num = num / 10;
	return (len);
}
