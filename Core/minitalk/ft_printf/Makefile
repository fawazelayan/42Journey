# -*- Makefile -*-

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_putchar.c ft_putstr.c ft_putdec.c ft_puthex.c ft_putpoin.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

ARC	=	ar crs

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(ARC) $(NAME) $(OBJS)
clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
