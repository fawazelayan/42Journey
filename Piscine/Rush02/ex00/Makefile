NAME = rush-02
SRC = main.c ft_src.c ft_rush02.c
OBJS = ${SRC:.c=.o}

CC		= cc
RM		= rm -rf
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
		
fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
