SRCS	= main.c read.c file.c ft_put.c ft_atol.c ft_str.c ft_list.c printer.c tools.c
INCLUDES = define.h read.h file.h ft_put.h dico.h ft_atol.h ft_str.h ft_list.h printer.h tools.h

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

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

.PHONY:		all clean fclean
