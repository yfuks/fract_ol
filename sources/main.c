/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:57:00 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/04 02:29:59 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static	void	init_env(t_env *e, char *argv)
{
	e->img = NULL;
	e->x = 0;
	e->y = 0;
	e->argv = ft_strdup(argv);
	e->padding = 10;
	e->ca = 0;
	e->cb = 0;
	e->zoom = 1;
	e->n = 100;
	e->x = 0;
	e->y = 0;
	e->r = 6;
	e->g = 2;
	e->b = 10;
	e->clock_prg = clock();
}

void			ft_put_error(char *argv, char *str1)
{
	if (argv != NULL && str1 != NULL)
	{
		ft_putstr_fd(ft_strjoin(argv, ": "), 2);
		ft_putstr_fd("\x1B[31m", 2);
		ft_putendl_fd(str1, 2);
		ft_putstr_fd("\x1B[37m", 2);
		exit(0);
	}
}

int				main(int ac, char **argv)
{
	t_env	e;
	(void)ac;
//	if (ac != 2)
//		ft_put_error("Usage", ft_strjoin(argv[0], " -JM"));
	if ((e.mlx = mlx_init()))
	{
		if (!(e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGTH, W_TITLE)))
			ft_put_error(argv[1], strerror(errno));
		else
		{
			init_env(&e, argv[0]);
			mlx_key_hook(e.win, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_hook(e.win, 6, (1L << 6), mouse_mouv, &e);
			mlx_hook(e.win, 4, (1L << 2), mouse_hook, &e);
			mlx_do_key_autorepeatoff(e.mlx);
			mlx_loop(e.mlx);
		}
	}
	else
		ft_put_error(argv[0], "Mlx initialization failed");
	return (0);
}
