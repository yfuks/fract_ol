/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:48:23 by yfuks             #+#    #+#             */
/*   Updated: 2014/12/30 16:27:59 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static void	put_pixel(t_env *e, int x, int y, int coloration)
{
	int				r;
	int				g;
	int				b;

	b = 0xFF -(coloration % 255);
	coloration /= 255;
	g = 0xFF - (coloration % 255);
	coloration /= 255;
	r = 0xFF - (coloration % 255);
	x *= 2;
	if (x >= 0 && y >= 0 && x < W_HEIGTH * 2 && y < W_WIDTH)
	{
		e->data[(y * e->sizeline) + (2 * x)] = r;
		e->data[(y * e->sizeline) + (2 * x) + 1] = g;
		e->data[(y * e->sizeline) + (2 * x) + 2] = b;
	}
}

void		draw_julia(t_env *e)
{
	double Za, temp, Zb;
	int	x, y, i;
	
	x = 0;
	while (x < W_WIDTH * 2)
	{
		y = 0;
		while (y < W_HEIGTH)
		{
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
			if (i < 9)
				put_pixel(e, x, y, 0xFFFFFF);
			else if (i != e->n)
				put_pixel(e, x, y, ((255-i * 10) << 16) + ((255-i * 10) << 8) + ((255-i * 10)));
			y++;
		}
		x++;
	}
}
