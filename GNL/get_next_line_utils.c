/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:54:11 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 09:45:39 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len_s2;
	size_t		len_s1;
	char		*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = -1;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (++i < len_s1)
		str[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		str[i + len_s1] = s2[i];
	str[len_s1 + len_s2] = '\0';
	return (str);
}

int	ft_strchr_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_zero_malloc(int i)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * i + 1);
	while (j++ < i)
		str[j] = '\0';
	return (str);
}
