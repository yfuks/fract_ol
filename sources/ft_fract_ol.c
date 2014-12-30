/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:17:58 by yfuks             #+#    #+#             */
/*   Updated: 2014/12/30 16:41:22 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static void	fill_img(t_env *e)
{
	if (!(e->data = mlx_get_data_addr
		(e->img, &e->bpp, &e->sizeline, &e->endian)))
		ft_putendl_fd(strerror(errno), 2);
	else
		draw_julia(e);
}

static void	draw(t_env *e)
{
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, W_HEIGTH, W_WIDTH);
	fill_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	float	padding;

	padding = (100 / (float)e->zoom);
	if (keycode == 65362)
		e->y += padding;
	else if (keycode == 65361)
		e->x -= padding;
	else if (keycode == 65364)
		e->y -= padding;
	else if (keycode == 65363)
		e->x += padding;
	else if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 65361 || keycode == 65363 || keycode == 65364)
		draw(e);
	return (0);
}

int			mouse_mouv(int x, int y, t_env *e)
{
	x -= W_WIDTH / 2;
	y -= W_HEIGTH / 2;
	e->ca = ((float)x / W_WIDTH);
	if (x < W_WIDTH / 2)
		e->ca *= 2;
	e->cb = ((float)y / W_HEIGTH);
	if (y < W_HEIGTH / 2)
		e->cb *= 2;
	draw(e);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		y -= W_WIDTH / 2;
		x -= W_HEIGTH / 2;
		y *= 2;
		x *= 2;
		e->x += (float)x / e->zoom;
		e->y -= (float)y / e->zoom;
		e->zoom += e->zoom;
		e->n += 5;
	}
 	else if (button == 5)
	{
		if (e->zoom > 1)
			e->zoom -= e->zoom / 2;
		e->n -= 5;
	}
	if (button == 5 || button == 4)
		draw(e);
	return (0);
}
