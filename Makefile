# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 10:05:54 by rvolberg          #+#    #+#              #
#    Updated: 2019/03/22 12:25:24 by tlaberro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME & COMPIPLATION

NAME =	wolf3d

CC =	clang

CFLAGS =	-Wall -Werror -Wextra

# INCLUDE

INCLUDE =	./inc/

# SRC & OBJ

SRC_PATH =	./src

SRC_NAME =	\
	main.c\
	init.c\
	support_init.c\
	parse.c\
	reader.c\
	utilities.c\
	player.c\
	output.c\
	key.c\
	raycast.c\
	draw_raycast.c\
	support_draw_raycast.c\
	move.c\
	draw_minimap.c\
	free_struct.c\


OBJ_NAME =	$(SRC_NAME:.c=.o)

SRC =	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ =	$(addprefix $(SRC_PATH)/,$(OBJ_NAME))

# MLX

MLX_PATH = /usr/local/

MLX =   -I $(MLX_PATH)includes -L $(MLX_PATH)lib/

FRAMEWORK =	-lmlx -framework OpenGL -framework AppKit

# LIBFT

LIBFT_PATH =	./libft/

LIBFT_LINK =	-L $(LIBFT_PATH) -lft

LIBFT =	$(LIBFT_PATH)libft.a

# RULES

all :	$(NAME)

libft_make :
	make -C $(LIBFT_PATH)

$(NAME) :	libft_make	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LINK) $(MLX) $(FRAMEWORK)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

.PHONY : clean fclean

clean :
	/bin/rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean :	clean
	/bin/rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re :	fclean all
	make -C $(LIBFT_PATH) re
