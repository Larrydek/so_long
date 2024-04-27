/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:12 by jde-clee          #+#    #+#             */
/*   Updated: 2023/02/07 04:54:32 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_spaces(long n)
{
	long	count;

	if (!n)
		return (0);
	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	i;
	long	num;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	i = ft_count_spaces(num);
	result = malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	result[--i] = 0;
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		result[--i] = (num % 10) + 48;
		num = num / 10;
	}
	return (result);
}

/* int main()
{   
	int n;
	char *result;
	n = 42;
	result = ft_itoa(n);

	printf("RESULT: %s\n", result);
	printf("%ld", ft_count_spaces(n));

	return (0);
} */
