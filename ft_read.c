/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:23:06 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 11:46:13 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>


char	*ft_read(int fd)
{
	char	*str;
	str = malloc (sizeof(char) * (READ_SIZE + 1));
	if (!str)
		return (NULL);
	str = malloc(sizeof(char) * (READ_SIZE + 1));
	int i = read(fd, str, READ_SIZE);
	str[i]= '\0';
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
