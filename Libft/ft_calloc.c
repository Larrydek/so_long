/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:11:59 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 17:18:34 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*matrix;

	matrix = (int *)malloc(count * size);
	if (!matrix)
		return (NULL);
	ft_memset(matrix, 0, count * size);
	return (matrix);
}
