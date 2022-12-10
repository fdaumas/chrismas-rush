/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_region.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:30:40 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 09:56:59 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include "rush.h"

t_region	ft_s_region(int fd)
{
	t_region	region;
	char		*str;
	char		**tmp;

	tmp = ft_split(get_next_line(fd), ':');
	region.name = ft_strtrim(tmp[0], " ");
	region.gpd = ft_atoi(tmp[1]);
	region.nearby = ft_split(tmp[2], '-');
	if (!region.name || !region.gpd || !region.nearby)
		return (write(2, "ERROR\n", 6), exit (0), region);
	return (region);
}
