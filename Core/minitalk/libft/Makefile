# -*- Makefile -*-

# COMMANDS #
ARC		=	ar crs
RM		=	rm -f

# ARCHIVE NAME #
ARCHIVE	=	libft.a

# DIRECTORIES #
SRCS_DR	=	srcs
INC_DR	=	inc

# SOURCE AND OBJECT FILES #
SRCS	=	$(wildcard $(SRCS_DR)/*.c)
OBJS	=	$(SRCS:.c=.o)

# COMPILER AND FLAGS #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I$(INC_DR)

# RULES #
all		:	$(ARCHIVE)

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(ARCHIVE)	:	$(OBJS)
	@$(ARC) $(ARCHIVE) $(OBJS)

clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(ARCHIVE)

re		:	fclean all

.PHONY	:	all clean fclean re