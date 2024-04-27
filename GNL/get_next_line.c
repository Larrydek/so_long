/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:32:12 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/23 20:39:29 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	LEE HASTA EL SALTO DE LÍNEA
	ACUMULA TODO EN BUFFER
*/
char	*read_next_line(int fd, char *save)
{
	char	temp[BUFFER_SIZE + 1];
	int		bytes_read;

	if (!save)
	{
		save = ft_strdup_gnl("");
		if (!save)
			return (NULL);
	}
	while (ft_strchr_gnl(save, '\n') == NULL)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(save);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		save = ft_strjoin_gnl(save, temp);
		if (!save)
			return (NULL);
	}
	return (save);
}

/*
	RETORNA LA STRING FINAL DESPUES DEL SALTO DE LINEA
*/
char	*save_final(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr_gnl(save, i + 1, ft_strlen_gnl(save) - i);
	free(save);
	save = line;
	if (!line)
		return (NULL);
	return (line);
}

char	*save_first(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr_gnl(save, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

/*
	FUNCIÓN GNL
*/
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(save);
		return (save = NULL, NULL);
	}
	save = read_next_line(fd, save);
	if (save)
		line = save_first(save);
	if (save)
		save = save_final(save);
	return (line);
}

/*
	MAIN
*/
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("texto.txt", O_RDONLY);
	while ((i < 10))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		printf("Linea: %d: %s\n", i, line);
		i++;
	}
	line = get_next_line(fd);
	printf("%s", line);
	system("leaks a.out");
	close(fd);
	//printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	return (0);
}
*/