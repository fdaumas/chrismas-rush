/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:04:26 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 09:46:00 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_to_end(char *line)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strchr_gnl (line);
	i = ft_strlen (line);
	if (i == j)
	{
		free(line);
		return (NULL);
	}
	str = malloc (sizeof (char) * (i - j));
	if (!str)
		return (free (line), NULL);
	k = 1;
	while (j + k < i)
	{
		str[k - 1] = line[j + k];
		k++;
	}
	str[k - 1] = '\0';
	return (free (line), str);
}

static char	*ft_complete(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		read_bytes;

	if (!line)
	{
		line = ft_zero_malloc(0);
		if (!line)
			return (NULL);
	}
	while (!line[ft_strchr_gnl(line)])
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 0)
			return (free (tmp), free(line), line);
		buffer[read_bytes] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free (tmp), free (line), line);
		free(tmp);
	}
	return (line);
}

static char	*ft_to_start(char *line)
{
	char	*buffer;
	int		i;
	int		j;

	i = ft_strchr_gnl(line);
	i += line[i] == '\n';
	if (i == 0)
		return (NULL);
	j = 0;
	buffer = malloc(sizeof(char) * (i + 1));
	if (!buffer)
		return (NULL);
	buffer[i] = '\0';
	while (i != j)
	{
		buffer[j] = line[j];
		j++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			count;

	if (!line)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	count = read(fd, 0, 0);
	if (fd < 0 || count < 0 || BUFFER_SIZE <= 0)
		return (free(line), line = NULL, NULL);
	line = ft_complete(line, fd);
	if (!line)
		return (free(line), line = NULL, NULL);
	buffer = ft_to_start(line);
	if (!buffer && line)
		return (free(line), line = NULL, NULL);
	line = ft_to_end(line);
	if (!line)
		return (free (line), line = NULL, buffer);
	return (buffer);
}
