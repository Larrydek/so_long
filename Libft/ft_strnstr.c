/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:45:43 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 22:59:48 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_haystack;
	size_t	len_needle;

	i = 0;
	j = 0;
	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	if (needle[i] == 0)
		return ((char *)haystack);
	if (len == 0 || haystack[0] == 0 || len_needle > len_haystack)
		return (NULL);
	while (i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (j == len_needle)
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// int main()
// {

//     char haystack[30] = "aaabcabcd";
// 	   char needle[10] = "aabc";
//     printf("strnstr: %s\n", strnstr(haystack, needle, -1));
//     printf("ft_strnstr: %s", ft_strnstr(haystack, needle, -1));
//     return (0);
// }