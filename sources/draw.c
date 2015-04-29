/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:11:56 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 01:52:22 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static void	fill_img(t_env *e, int (*f)(t_env *, int, int))
{
	t_coord coord;

	coord.x = W_WIDTH / 2 - (e->x * (e->zoom / 4.1));
	coord.y = W_HEIGTH - 20 + (e->y * (e->zoom / 1.2));
	if (!(e->data = mlx_get_data_addr
		(e->img, &e->bpp, &e->sizeline, &e->endian)))
		ft_putendl_fd(strerror(errno), 2);
	else if (!e->tree)
		draw_fractal(e, f);
	else
		draw_tree(e, coord, -(M_PI / 2), e->n);
}

void		draw(t_env *e, int (*f)(t_env *, int, int))
{
	if ((e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGTH)))
	{
		fill_img(e, f);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
	}
}
