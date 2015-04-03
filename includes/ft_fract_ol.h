/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:06:12 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/01 17:26:24 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FRACT_OL_H
# define FT_FRACT_OL_H
# include <mlx.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <complex.h>
# include <stdlib.h>
# include "libft.h"

# define W_HEIGTH 600
# define W_WIDTH 600
# define W_TITLE "Fract_ol 42"

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*argv;
	int				bpp;
	int				sizeline;
	int				endian;
	float			x;
	float			y;
	int				padding;
	int				power;
	double			ca;
	double			cb;
	double			zoom;
	int				n;
	clock_t			clock_prg;
}					t_env;
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_mouv(int x, int y, t_env *e);
void				map_pixels(t_env *e);
void				reset_param(t_env *e);
void				ft_put_error(char *argv, char *str1);
void				draw_julia(t_env *e);
#endif