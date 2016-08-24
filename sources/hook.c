/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:09:55 by yfuks             #+#    #+#             */
/*   Updated: 2016/08/24 20:32:51 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int			expose_hook(t_env *e)
{
	draw(e, e->f);
	return (0);
}

static int	hook_colors(int keycode, t_env *e)
{
	if (keycode == KEY_ONE && e->r > 0)
		e->r--;
	else if (keycode == KEY_FOUR)
		e->r = 5;
	else if (keycode == KEY_SEVEN)
		e->r++;
	else if (keycode == KEY_TWO && e->g > 0)
		e->g--;
	else if (keycode == KEY_FIVE)
		e->g = 5;
	else if (keycode == KEY_EIGHT)
		e->g++;
	else if (keycode == KEY_THREE && e->b > 0)
		e->b--;
	else if (keycode == KEY_SIX)
		e->b = 5;
	else if (keycode == KEY_NINE)
		e->b++;
	if (keycode == KEY_ONE || keycode == KEY_TWO || keycode == KEY_THREE
		|| keycode == KEY_FOUR || keycode == KEY_FIVE || keycode == KEY_SIX
		|| keycode == KEY_SEVEN || keycode == KEY_EIGHT || keycode == KEY_NINE)
		return (1);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP)
		e->y -= 50 / e->zoom;
	else if (keycode == KEY_DOWN)
		e->y += 50 / e->zoom;
	else if (keycode == KEY_LEFT)
		e->x += 50 / e->zoom;
	else if (keycode == KEY_RIGHT)
		e->x -= 50 / e->zoom;
	else if (keycode == KEY_PLUS)
		e->n++;
	else if (keycode == KEY_MINUS)
		e->n--;
	else if (keycode == KEY_C)
		e->c = (e->c) ? 0 : 1;
	else if (keycode == KEY_R && !e->tree)
		init_env(e, e->argv);
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT || keycode == KEY_MINUS || keycode == KEY_PLUS
		|| hook_colors(keycode, e) || hook_f(keycode, e) || keycode == KEY_R)
		draw(e, e->f);
	return (0);
}

int			mouse_mouv(int x, int y, t_env *e)
{
	if (((FPS) * (clock() - e->clock_prg)) / CLOCKS_PER_SEC > 1 && e->c && !e->tree)
	{
		e->clock_prg = clock();
		x -= W_WIDTH / 2;
		y -= W_HEIGTH / 2;
		e->ca = ((float)x / W_WIDTH) * 2;
		e->cb = ((float)y / W_HEIGTH) * 2;
		draw(e, e->f);
	}
	else if (((950) * (clock() - e->clock_prg)) / CLOCKS_PER_SEC > 1 && e->c && e->tree)
	{
		e->clock_prg = clock();
		e->size_tree = (float)y / W_HEIGTH;
		e->size_tree2 = (float)x / W_WIDTH;
		draw(e, e->f);
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	x -= W_WIDTH / 2;
	y -= W_HEIGTH / 2;
	if (button == SCROLL_UP)
	{
		e->zoom *= 1.1;
		e->x += x / e->zoom / 2.51;
		e->y -= y / e->zoom / 2.51;
	}
	else if (button == SCROLL_DOWN && e->zoom > 0.1)
		e->zoom /= 1.1;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		draw(e, e->f);
	return (0);
}
