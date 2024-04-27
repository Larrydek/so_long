/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:44:45 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 22:53:13 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*final_s;
	size_t	i;

	i = 0;
	final_s = ft_strdup(s);
	if (final_s == NULL)
		return (NULL);
	while (final_s[i])
	{
		final_s[i] = f(i, final_s[i]);
		i++;
	}
	return (final_s);
}
