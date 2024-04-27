/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:31:36 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/23 20:40:10 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (str + i);
	else
		return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len_s1s2;
	char	*str;

	i = 0;
	j = 0;
	len_s1s2 = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = (char *)malloc((len_s1s2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_gnl(s) <= start)
		return (0);
	if (ft_strlen_gnl(&s[start]) < len)
		len = ft_strlen_gnl(&s[start]);
	if (!len)
		return (NULL);
	aux = (char *)malloc(len + 1 * sizeof(char));
	if (!aux)
		return (NULL);
	while (s[start] != 0 && i < len)
		aux[i++] = s[start++];
	aux[i] = 0;
	return (aux);
}
