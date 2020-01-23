SRCS	= main.c ft_atoi.c ft_calc.c ft_calculate.c ft_put.c
INCLUDES = ft_atoi.h ft_calc.h ft_calculate.h ft_put.h ft_operator.h

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:		${INCLUDES}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
