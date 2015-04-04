/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:11:56 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 03:29:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static void	fill_img(t_env *e)
{
	t_coord coord;

	coord.x = W_WIDTH / 2 - e->x;
	coord.y = W_HEIGTH - 20 + e->y;
	if (!(e->data = mlx_get_data_addr
		(e->img, &e->bpp, &e->sizeline, &e->endian)))
		ft_putendl_fd(strerror(errno), 2);
	else
		draw_fractal(e, burning_ship);
}

void	draw(t_env *e)
{
	if ((e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGTH)))
	{
		fill_img(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
	}
}
