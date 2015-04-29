/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:06:12 by yfuks             #+#    #+#             */
/*   Updated: 2015/04/29 02:21:56 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACT_OL_H
# define FT_FRACT_OL_H
# include <mlx.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include "libft.h"

# define W_HEIGTH	600
# define W_WIDTH	600
# define W_TITLE	"Fract_ol 42"

# define KEY_ESC	53
# define KEY_PLUS	69
# define KEY_MINUS	78
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126

# define KEY_ONE	83
# define KEY_TWO	84
# define KEY_THREE	85
# define KEY_FOUR	86
# define KEY_FIVE	87
# define KEY_SIX	88
# define KEY_SEVEN	89
# define KEY_EIGHT	91
# define KEY_NINE	92

# define KEY_C		8
# define KEY_R		15

# define KEY_F1		122
# define KEY_F2		120
# define KEY_F3		99
# define KEY_F4		118
# define KEY_F5		96
# define KEY_F6		97
# define KEY_F7		98

# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define FPS		30

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
	float			size_tree;
	float			size_tree2;
	int				n;
	int				r;
	int				g;
	int				b;
	clock_t			clock_prg;
	int				tree;
	int				(*f)(struct s_env *, int, int);
	int				c;
	int				draw_end;
}					t_env;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_mouv(int x, int y, t_env *e);
void				reset_param(t_env *e);
void				ft_put_error(char *argv, char *str1);
void				put_pixel(t_env *e, int x, int y, int coloration);
int					julia(t_env *e, int x, int y);
int					randomf(t_env *e, int x, int y);
int					randomf2(t_env *e, int x, int y);
int					mandelbrot(t_env *e, int x, int y);
int					sponge(t_env *e, int x, int y);
int					burning_ship(t_env *e, int x, int y);
void				draw_tree(t_env *e, t_coord start, double angle, int iter);
void				draw_fractal(t_env *e, int(*f)(t_env *, int, int));
void				draw(t_env *e, int(*f)(t_env *, int, int));
void				parse_arg(t_env *e, int ac, char **av);
void				put_infos(void);
void				init_env(t_env *e, char *argv);
int					hook_f(int keycode, t_env *e);
#endif
