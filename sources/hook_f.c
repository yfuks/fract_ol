/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 01:34:19 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 02:01:01 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int		hook_f(int keycode, t_env *e)
{
	e->f = (keycode == KEY_F1) ? julia : e->f;
	e->f = (keycode == KEY_F2) ? mandelbrot : e->f;
	e->f = (keycode == KEY_F3) ? burning_ship : e->f;
	if (keycode == KEY_F4)
	{
		e->tree = 1;
		e->n = 10;
	}
	else if (keycode == KEY_F5)
		e->f = sponge;
	else if (keycode == KEY_F6)
		e->f = randomf;
	else if (keycode == KEY_F7)
		e->f = randomf2;
	if (keycode == KEY_F1 || keycode == KEY_F2 || keycode == KEY_F3 ||
		keycode == KEY_F5 || keycode == KEY_F6 || keycode == KEY_F7)
	{
		e->tree = 0;
		e->n = 100;
	}
	if (keycode == KEY_F1 || keycode == KEY_F2 || keycode == KEY_F3 ||
		keycode == KEY_F4 || keycode == KEY_F5 || keycode == KEY_F6 ||
		keycode == KEY_F7)
		return (1);
	return (0);
}
