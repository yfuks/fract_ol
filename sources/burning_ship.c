/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 00:44:57 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 01:51:47 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		burning_ship(t_env *e, int x, int y)
{
	int		i;
	double	za;
	double	zb;
	double	tmp;

	e->ca = 1.5 * (x - W_WIDTH / 2) / (0.5 * e->zoom * W_WIDTH)
		+ (e->x / W_WIDTH / 1.30) - 0.5;
	e->cb = (y - W_HEIGTH / 2) / (0.5 * e->zoom * W_HEIGTH)
		- (e->y / W_HEIGTH / 1.97);
	za = 0;
	zb = 0;
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->n)
	{
		tmp = za;
		za = ft_fabs(tmp * tmp) - zb * zb + e->ca;
		zb = 2 * ft_fabs(tmp * zb) + e->cb;
		i++;
	}
	return (i);
}
