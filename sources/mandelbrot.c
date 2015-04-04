/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:51:36 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 06:20:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		mandelbrot(t_env *e, int x, int y)
{
	int		i;
	double	Za;
	double	Zb;
	double	tmp;

	e->ca = 1.5 * (x - W_WIDTH / 2) / (0.5 * e->zoom * W_WIDTH)
		+ (e->x / W_WIDTH / 1.37) - 0.5;
	e->cb = (y - W_HEIGTH / 2) / (0.5 * e->zoom * W_HEIGTH)
		- (e->y / W_HEIGTH / 1.92);
	Za = 0;
	Zb = 0;
	i = 0;
	while (Za * Za + Zb * Zb <= 4 && i < e->n)
	{
		tmp = Za;
		Za = tmp * tmp - Zb * Zb + e->ca;
		Zb = 2 * tmp * Zb + e->cb;
		i++;
	}
	return (i);
}
