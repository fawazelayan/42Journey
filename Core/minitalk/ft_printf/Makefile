# -*- Makefile -*-

NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c srcs/ft_putchar.c	\
			srcs/ft_putstr.c srcs/ft_putdec.c	\
			srcs/ft_puthex.c srcs/ft_putpoin.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Iinc

ARC		=	ar crs
RM		=	rm -f

all		:	$(NAME)

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(ARC) $(NAME) $(OBJS)
clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
