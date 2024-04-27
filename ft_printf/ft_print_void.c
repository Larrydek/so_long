/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:11:28 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/03 20:21:27 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_void(unsigned long int n, int *len)
{
	if (n >= 16)
	{
		ft_void(n / 16, len);
		ft_void(n % 16, len);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0', len);
		else
			ft_char((n - 10) + 'a', len);
	}
}

int	*ft_print_void(unsigned long int ptr, int *len)
{
	if (ptr == 0)
	{
		write(1, "0", 1);
		(*len)++;
	}
	else
		ft_void(ptr, len);
	return (len);
}
