/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:35:43 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/03 20:27:09 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char const *type, va_list args, int *len)
{
	if (*type == 'c')
		ft_char(va_arg(args, int), len);
	else if (*type == 's')
		ft_string(va_arg(args, char *), len);
	else if (*type == 'd' || *type == 'i')
		ft_print_num(va_arg(args, int), len);
	else if (*type == 'u')
		ft_print_uint(va_arg(args, int), len);
	else if (*type == 'x' || *type == 'X')
		ft_print_hex(va_arg(args, unsigned int), *type, len);
	else if (*type == '%')
		ft_char('%', len);
	else if (*type == 'p')
	{
		write(1, "0x", 2);
		(*len) += 2;
		ft_print_void(va_arg(args, unsigned long int), len);
	}
}

int	ft_printf(char const *type, ...)
{
	va_list	args;
	int		len;

	va_start (args, type);
	len = 0;
	while (*type)
	{
		if (*type == '%')
		{
			type++;
			ft_format(type, args, &len);
			type++;
		}
		else
		{
			write(1, type, 1);
			len++;
			type++;
		}
	}
	va_end (args);
	return (len);
}
