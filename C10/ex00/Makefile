SRCS		= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
