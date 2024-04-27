/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:20:59 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 23:00:29 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *)s;
	while (str[i] != (char)c && i > 0)
		i--;
	if (str[i] == (char)c)
		return (str + i);
	else
		return (NULL);
}

// int main()
// {
//     const char *s = "abcdefghijk";
//     int c;

//     c = 'a';

//     printf("%s", ft_strrchr(s, c));

//     return (0);
// }