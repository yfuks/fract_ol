/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:28:22 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/03 23:46:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	draw_fractal(t_env *e, int (*f)(t_env *, int, int))
{
	int		x;
	int		y;
	int		i;
	int		color;

	y = 0;
	while (y < W_HEIGTH)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			i = (*f)(e, x, y);
			color = ((255 - i * e->r) << 16) + ((255 - i * e->g) << 8)
				+ (255 - i * e->b);
			if (i != e->n)
				put_pixel(e, x, y, color); 
			x++;
		}
		y++;
	}
}
