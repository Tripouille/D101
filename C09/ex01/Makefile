SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCLUDESDIR = ../includes/ft.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
AR		= ar rc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I includes

all:		${NAME}

.c.o:		${INCLUDESDIR}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
