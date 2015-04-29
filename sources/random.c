/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:13:31 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 01:55:21 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int			randomf(t_env *e, int x, int y)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * (float)x / W_WIDTH - 2) / e->zoom) + ((e->x / W_WIDTH));
	zb = ((-4 * (float)y / W_HEIGTH + 2) / e->zoom) + ((e->y / W_HEIGTH));
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->n)
	{
		temp = za;
		za = za * za - zb * zb + e->ca;
		zb = sin(2 * temp * zb + e->cb);
		i++;
	}
	return (i);
}
