/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:17:58 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/01 17:31:20 by yfuks            ###   ########.fr       */
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
	if ((e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGTH)))
	{
		fill_img(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
	}
}

int			expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP)
		e->y -= 50;
	else if (keycode == KEY_DOWN)
		e->y += 50;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		draw(e);
	return (0);
}

int			mouse_mouv(int x, int y, t_env *e)
{
	if ((30 * (clock() - e->clock_prg)) / CLOCKS_PER_SEC > 1)
	{
		e->clock_prg = clock();
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
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
