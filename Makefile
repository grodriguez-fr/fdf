# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 15:35:05 by gurodrig          #+#    #+#              #
#    Updated: 2023/03/28 11:23:17 by gurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	= src/main.c \
	  src/utils.c \
	  src/matrix.c \
	  src/camera_basic.c \
	  src/camera_matrix.c \
	  src/matrix_operations.c \
	  src/parsing.c
MLX_PATH	= minilibx-linux
INCLUDE_FOLDER	= includes
MLX_LIB		= $(MLX_PATH)/libmlx_Linux.a
MLX_INC		= -I$(MLX_PATH)
X11_LIB		= -L/usr/X11R6/lib -lX11
XEXT_LIB	= -lXext

HEADERS	= includes/fdf.h includes/get_next_line.h includes/libft.h

OBJ_FOLDER = obj
OBJS	= $(addprefix $(OBJ_FOLDER)/, $(notdir $(SRCS:.c=.o)))

NAME	= fdf 

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -lm

LIBFT	= libft/libft.a

$(OBJ_FOLDER)/%.o: src/%.c
	${CC} -I$(INCLUDE_FOLDER) $(MLX_INC) -c $< -o $@ $(CFLAGS)


all: $(NAME)


$(NAME): $(OBJS) $(HEADERS) $(LIBFT) $(MLX_LIB)
	${CC} $(CFLAGS) $(LIBFT) $(MLX_INC) $(MLX_LIB) $(X11_LIB) $(XEXT_LIB) -o $@ $^

$(MLX_LIB):
	make -sC $(MLX_PATH)

$(LIBFT):
	make -C libft
clean :
	rm -rf $(OBJ_FOLDER)/*.o
	make clean -C libft
	make clean -C $(MLX_PATH)

fclean : clean
	rm -f $(LIBFT)	
	rm -f $(NAME)
	rm -f $(MLX_LIB)

re : fclean all

.PHONY: all clean fclean re
