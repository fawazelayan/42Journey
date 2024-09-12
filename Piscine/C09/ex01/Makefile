NAME = rush-02
SRC = main.c
OBJS = ${SRC:.c=.o}

CC		= cc
RM		= rm -rf
CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}


clean:
		${RM} ${OBJS}
		
fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
