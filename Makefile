#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/01 14:18:08 by yfuks             #+#    #+#              #
#    Updated: 2015/04/01 14:24:20 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = sources/ft_fract_ol.c		\
		sources/ft_put_pixel.c	\
		sources/main.c			\
		libft/libft.a

HEAD = ./includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang

LIB = /usr/x11/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME):
	make -C ./libft
	$(CC) $(FLAGS) $(SRC) -I $(HEAD) -L $(LIB) -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all