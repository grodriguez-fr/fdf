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
	  src/parsing.c

INCLUDE_FOLDER	= includes
HEADERS	= includes/fdf.h includes/get_next_line.h includes/libft.h

OBJ_FOLDER = obj
OBJS	= $(addprefix $(OBJ_FOLDER)/, $(notdir $(SRCS:.c=.o)))

NAME	= fdf 

CC	= cc
CFLAGS	= -Wall -Wextra -Werror 

LIBFT	= libft/libft.a

$(OBJ_FOLDER)/%.o: src/%.c
	${CC} -I$(INCLUDE_FOLDER) -c $< -o $@ $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT)
	${CC} $(CFLAGS) $(LIBFT) -o $@ $^

$(LIBFT):
	make -C libft
clean :
	rm -rf $(OBJ_FOLDER)/*.o
	make clean -C libft

fclean : clean
	rm -f $(LIBFT)	
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
