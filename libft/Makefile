SRCS	= ft_memcpy.c \
		ft_memmove.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_itoa.c \
		ft_split.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strmapi.c \
		ft_strlcpy.c \
		ft_calloc.c \
		get_next_line.c \
		ft_strncmp.c
SRCS_BONUS	=	ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstdelone_bonus.c
OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o} ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
HEADER	= libft.h get_next_line.h

%.o:	%.c $(HEADER)
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}

bonus:	.bonus

.bonus:	${OBJS_BONUS}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
			touch .bonus

all:		${NAME}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:	clean
			rm -f ${NAME} .bonus

re:		fclean all

rebonus:	fclean bonus
.PHONY:		clean fclean re
