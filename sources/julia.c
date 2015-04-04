/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:50:06 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/03 23:50:30 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int			julia(t_env *e, int x, int y)
{
	double	Za;
	double	Zb;
	double	temp;
	int		i;

	Za = ((4 * (float)x / W_WIDTH - 2) / e->zoom) + ((e->x / W_WIDTH));
	Zb = ((-4 * (float)y / W_HEIGTH + 2) / e->zoom) + ((e->y / W_HEIGTH));
	i = 0;
	while (Za * Za + Zb * Zb <= 4 && i < e->n)
	{
		temp = Za;
		Za = Za * Za - Zb * Zb + e->ca;
		Zb = 2 * temp * Zb + e->cb;
		i++;
	}
	return (i);
}
