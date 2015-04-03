/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:48:23 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/03 23:46:43 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	put_pixel(t_env *e, int x, int y, int coloration)
{
	int		r;
	int		g;
	int		b;

	r = (coloration & 0xFF0000) >> 16;
	g = (coloration & 0xFF00) >> 8;
	b = (coloration & 0xFF);
	if (y >= 0 && x >= 0 && y < W_HEIGTH && x < W_WIDTH)
	{
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x) + 2] = r;
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x) + 1] = g;
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x)] = b;
	}
}

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
