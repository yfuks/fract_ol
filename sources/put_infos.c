/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:01:58 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 01:54:44 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	put_infos(void)
{
	ft_putendl("Infos :");
	ft_putendl("---FRACTALS---\n");
	ft_putendl("J     : Julia");
	ft_putendl("M     : Mandelbrot");
	ft_putendl("B     : Burning Ship");
	ft_putendl("T     : Tree");
	ft_putendl("S     : Menger Sponge");
	ft_putendl("R1    : Fractal random 1");
	ft_putendl("R2    : Fractal random 2");
	ft_putendl("\nUsage : ./fractol -JMBTS -R1 -R2");
	ft_putendl("\n---KEYS HOOKS---\n");
	ft_putendl("ESC          : quit");
	ft_putendl("Arrows keys  : move in the fractal");
	ft_putendl("Minus / Plus : increase or decrease the iterations number");
	ft_putendl("Numeric pad  : change color value");
	ft_putendl("C            : lock/unlock mouse move hook");
	ft_putendl("R            : reset modifications");
	ft_putendl("F1 to F7     : set the fractal");
	ft_putendl("\n---MOUSE HOOKS---\n");
	ft_putendl("Scroll up/down : change the zoom value");
	ft_putstr("Move           : change the coefficents");
	ft_putendl(" (in Julia, tree, random 1 and random 2)");
	exit(0);
}
