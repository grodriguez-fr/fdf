SRCS	= srcs/ft_printf.c \
		srcs/put_char_str.c \
		srcs/put_int_uint.c \
		srcs/put_addr.c \
		srcs/put_hex.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

.c.o:	
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:	
			rm -f ${OBJS}

fclean:	clean 
			rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
