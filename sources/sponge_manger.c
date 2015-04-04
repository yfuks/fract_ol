/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sponge_manger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 00:33:27 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 06:12:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		sponge(t_env *e, int x, int y)
{
	int		i;

	i = 0;
	e->zoom = (e->zoom >= 5) ? 1.6 : e->zoom;
	x = (x) / e->zoom;
	y = (y) / e->zoom;
	x = ft_fabs(x);
	y = ft_fabs(y);
	while ((x > 0 || y > 0) && i < e->n)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);
}
