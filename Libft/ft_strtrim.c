/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:25:07 by jde-clee          #+#    #+#             */
/*   Updated: 2023/03/13 23:02:20 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*cast_s1;

	i = 0;
	j = ft_strlen(s1) - 1;
	cast_s1 = (char *)s1;
	if (!s1[0])
		return (ft_strdup("\0"));
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	while (ft_strchr(set, s1[j]) != NULL && j > 0)
		j--;
	return (ft_substr(cast_s1, i, j - i + 1));
}

/* int main()
{
	char const *s1 = "";
	char const *set = "cdef";
	
	printf("%s", ft_strtrim(s1, set));
	
	return 0;
} */