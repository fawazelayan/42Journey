# -*- Makefile -*- #

NAME	=	libft.a

SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c	\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c		\
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c		\
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c		\
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_split.c			\
		ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_tolower.c ft_toupper.c	\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

BONUS_S	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c		\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	=	$(SRCS:.c=.o)
BONUS_O	=	$(BONUS_S:.c=.o)

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCS	=	libft.h

ARC	=	ar crs

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(ARC) $(NAME) $(OBJS)

bonus	:	$(OBJS) $(BONUS_O)
		$(ARC) $(NAME) $(OBJS) $(BONUS_O)

clean	:
		$(RM) $(OBJS) $(BONUS_O)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
