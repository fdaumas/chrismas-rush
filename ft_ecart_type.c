/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ecart_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:29:24 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 11:09:25 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

float	ft_ecart_type(int *total, int nb_region)
{
	int		i;
	float	result;
	float	moyenne;

	i = -1;
	result = 0;
	while (++i <= nb_region - 1)
		result += total[i];
	moyenne = result / nb_region;
	i = -1;
	result = 0;
	while (++i <= nb_region - 1)
		result = ((total[i] - moyenne) * (total[i] - moyenne)) + result;
	result = sqrt(result / nb_region);
	return (result);
}
