/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sponge_manger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 00:33:27 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 03:28:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		sponge(t_env *e, int x, int y)
{
	int		i;

	i = 0;
	x = (x + e->x) / e->zoom;
	x = ft_fabs(x);
	y = (y + e->y) / e->zoom;
	y = ft_fabs(y);
	e->zoom = (e->zoom >= 5) ? 1.6 : e->zoom;
	while ((x > 0 || y > 0) && i < e->n)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (20);
		x /= 3;
		y /= 3;
		i++;
	}
	return (0);
}
