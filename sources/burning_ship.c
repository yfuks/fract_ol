/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 00:44:57 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 00:53:27 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		burning_ship(t_env *e, int x, int y)
{
	int		i;
	double	Za;
	double	Zb;
	double	tmp;

	e->ca = 1.5 * (x - W_WIDTH / 2) / (0.5 * e->zoom * W_WIDTH) + e->x / 500 - 0.5;
	e->cb = (y - W_HEIGTH / 2) / (0.5 * e->zoom * W_HEIGTH) - e->y / 500;
	Za = 0;
	Zb = 0;
	i = 0;
	while (Za * Za + Zb * Zb <= 4 && i < e->n)
	{
		tmp = Za;
		Za = ft_fabs(tmp * tmp) - Zb * Zb + e->ca;
		Zb = 2 * ft_fabs(tmp * Zb) + e->cb;
		i++;
	}
	return (i);
}
