/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:23:06 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 11:04:56 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>


char	*ft_read(int fd)
{
	char	*str;
	//int		fd;

	str = malloc (sizeof(char) * (READ_SIZE + 1));
	if (!str)
		return (NULL);
	//fd = open(file_in, O_RDONLY);
	str = malloc(sizeof(char) * (READ_SIZE + 1));
	while (read(fd, str, READ_SIZE) > 0)
	{
		str = realloc(str, READ_SIZE * 2 + sizeof(str));
		if (!str)
			return (free (str), NULL);
	}
	//close(fd);
	return (str);
}

#include <stdio.h>

int main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = ft_read(fd);
	printf("%s\n", str);
	close(fd);
}
