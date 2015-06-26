#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/01 14:18:08 by yfuks             #+#    #+#              #
#    Updated: 2015/06/26 13:07:03 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = sources/draw.c			\
		sources/ft_put_pixel.c	\
		sources/main.c			\
		libft/libft.a			\
		sources/hook.c			\
		sources/draw_fractal.c	\
		sources/julia.c			\
		sources/mandelbrot.c	\
		sources/sponge_manger.c	\
		sources/burning_ship.c	\
		sources/draw_tree.c		\
		sources/random.c		\
		sources/random2.c		\
		sources/parse_arg.c		\
		sources/put_infos.c		\
		sources/hook_f.c		\
		minilibx_macos/libmlx.a

HEAD = ./includes -I ./minilibx_macos

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang

LIB = ./minilibx_macos -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx_macos
	$(CC) $(FLAGS) $(SRC) -I $(HEAD) -L $(LIB) -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all