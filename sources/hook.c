/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:09:55 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/03 23:47:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

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
	else if (keycode == KEY_LEFT)
		e->x += 50;
	else if (keycode == KEY_RIGHT)
		e->x -= 50;
	else if (keycode == KEY_PLUS)
		e->n++;
	else if (keycode == KEY_MINUS)
		e->n--;
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT || keycode == KEY_MINUS || keycode == KEY_PLUS)
		draw(e);
	return (0);
}

int			mouse_mouv(int x, int y, t_env *e)
{
	if ((FPS * (clock() - e->clock_prg)) / CLOCKS_PER_SEC > 1)
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
