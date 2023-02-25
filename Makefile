SRCS	= srcs/fdf.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= fdf

.c.o:	
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} includes/fdf.h
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:	
			rm -f ${OBJS}

fclean:	clean 
			rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
