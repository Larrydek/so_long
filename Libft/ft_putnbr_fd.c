/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:36:48 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 21:04:58 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s[2];
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 0)
	{
		if (n == 0)
			write(fd, "0", 1);
		else
		{
			s[0] = (num % 10) + 48;
			num = num / 10;
			if (num > 0)
				ft_putnbr_fd(num, fd);
			write(fd, &s[0], 1);
		}
	}
}

/* int main()
{
	int n;
	int fd;

	n = -283648;
	fd = 2;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);

	n = 0;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);

	n = 2345435;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);

	return 0;
} */
