/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:22:10 by mbrement          #+#    #+#             */
/*   Updated: 2022/12/10 11:18:49 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "math.h"
# include <fcntl.h>
# include <stdlib.h>
# define READ_SIZE 4096

typedef struct s_region
{
	char	*name;
	int		gpd;
	char	**nearby;
}			t_region;

float	ft_ecart_type(int *total, int nb_region);

#endif