/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 23:31:34 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 02:19:50 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

static int	parse_arg_2(t_env *e, char **av, int *i, int *i2)
{
	e->f = (av[*i][*i2] == 'J') ? julia : e->f;
	if (av[*i][*i2] == 'M')
		e->f = mandelbrot;
	else if (av[*i][*i2] == 'B')
		e->f = burning_ship;
	else if (av[*i][*i2] == 'T')
	{
		e->tree = 1;
		e->n = 10;
	}
	else if (av[*i][*i2] == 'S')
		e->f = sponge;
	else if (av[*i][*i2] == 'R' && av[*i][*i2 + 1] == '1')
	{
		*i2 += 1;
		e->f = randomf;
	}
	else if (av[*i][*i2] == 'R' && av[*i][*i2 + 1] == '2')
	{
		*i2 += 1;
		e->f = randomf2;
	}
	else if (e->f != julia)
		return (0);
	return (1);
}

static void	put_wrong_arg(t_env *e)
{
	ft_putendl("Wrong arguments ");
	ft_put_error("Usage", ft_strjoin(e->argv, " -JMBTS -R1 -R2 [--infos]"));
}

void		parse_arg(t_env *e, int ac, char **av)
{
	int		i;
	int		i2;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			i2 = 1;
			while (av[i][i2])
			{
				if (parse_arg_2(e, av, &i, &i2))
					;
				else if (strncmp(&av[i][i2], "-infos", 6) == 0)
					put_infos();
				else
					put_wrong_arg(e);
				i2++;
			}
		}
		else
			put_wrong_arg(e);
		i++;
	}
}
