/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 01:12:22 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 06:43:05 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static void	put_line(t_env *e, t_coord start, t_coord end, int color)
{
	double	dd;
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		put_pixel(e, x, y, color);
		x += dx;
		y += dy;
	}
}

void		draw_tree(t_env *e, t_coord start, double angle, int iter)
{
	t_coord	end;
	int		color;

	if (iter > 0)
	{
		end.x = start.x + (cos(angle) * iter * 6 * e->size_tree) * e->zoom;
		end.y = start.y + (sin(angle) * iter * 9 * e->size_tree) * e->zoom;
		color = ((50 + e->r * iter) << 16) + ((e->g * iter) << 8)
			+ (155 - e->b * iter);
		put_line(e, start, end, color);
		draw_tree(e, end, angle - (M_PI / 8 * e->ca * 2), iter - 1);
		draw_tree(e, end, angle + (M_PI / 8 * e->ca * 2), iter - 1);
	}
}
