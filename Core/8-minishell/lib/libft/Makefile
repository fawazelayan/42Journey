#  ========================  #
#							 #
#  	    -*- LIBFT -*-		 #
#							 #
#  ========================	 #	

#  ========================  #
#	    FILE STRUCTURE		 #
#  ========================  #
ARCHIVE		=	libft.a

SRCS_DR		=	srcs
OBJS_DR		=	objs
INC_DR		=	incs

#  ========================  #
#	      COMMANDS			 #
#  ========================  #
AR	=	ar crs
RM	=	rm -rf

#  ========================  #
#		FILES AND PATHS		 #
#  ========================  #
SRCS	=	\
		$(SRCS_DR)/ft_atoi.c \
		$(SRCS_DR)/ft_bzero.c \
		$(SRCS_DR)/ft_calloc.c \
		$(SRCS_DR)/ft_isalnum.c \
		$(SRCS_DR)/ft_isalpha.c \
		$(SRCS_DR)/ft_isascii.c \
		$(SRCS_DR)/ft_isdigit.c \
		$(SRCS_DR)/ft_isprint.c \
		$(SRCS_DR)/ft_itoa.c \
		$(SRCS_DR)/ft_lstadd_back.c \
		$(SRCS_DR)/ft_lstadd_front.c \
		$(SRCS_DR)/ft_lstclear.c  \
		$(SRCS_DR)/ft_lstdelone.c \
		$(SRCS_DR)/ft_lstiter.c \
		$(SRCS_DR)/ft_lstlast.c \
		$(SRCS_DR)/ft_lstmap.c \
		$(SRCS_DR)/ft_lstnew.c \
		$(SRCS_DR)/ft_lstsize.c \
		$(SRCS_DR)/ft_memchr.c \
		$(SRCS_DR)/ft_memcmp.c \
		$(SRCS_DR)/ft_memcpy.c \
		$(SRCS_DR)/ft_memmove.c \
		$(SRCS_DR)/ft_memset.c \
		$(SRCS_DR)/ft_putchar_fd.c \
		$(SRCS_DR)/ft_putendl_fd.c \
		$(SRCS_DR)/ft_putnbr_fd.c \
		$(SRCS_DR)/ft_putstr_fd.c \
		$(SRCS_DR)/ft_split.c \
		$(SRCS_DR)/ft_strcat.c \
		$(SRCS_DR)/ft_strchr.c \
		$(SRCS_DR)/ft_strcmp.c \
		$(SRCS_DR)/ft_strcpy.c \
		$(SRCS_DR)/ft_strdup.c \
		$(SRCS_DR)/ft_striteri.c \
		$(SRCS_DR)/ft_strjoin.c \
		$(SRCS_DR)/ft_strlcat.c \
		$(SRCS_DR)/ft_strlcpy.c \
		$(SRCS_DR)/ft_strlen.c \
		$(SRCS_DR)/ft_strmapi.c \
		$(SRCS_DR)/ft_strncmp.c \
		$(SRCS_DR)/ft_strnstr.c \
		$(SRCS_DR)/ft_strtrim.c \
		$(SRCS_DR)/ft_substr.c \
		$(SRCS_DR)/ft_tolower.c \
		$(SRCS_DR)/ft_toupper.c

OBJS	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS))

#  ========================  #
#	   COMPILATION RULES	 #
#  ========================  #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror \
			-I$(INC_DR)

#  ========================  #
#			RULES			 #
#  ========================  #
all		:	$(ARCHIVE)

re		:	fclean all

.PHONY	:	all clean fclean re

# Compile .o files into objs/
$(OBJS_DR)/%.o	:	$(SRCS_DR)/%.c	| $(OBJS_DR)
	@$(CC) $(CFLAGS) -c $< -o $@

#  ========================  #
#		  BUILDING			 #
#  ========================  #
$(OBJS_DR)	:
	@mkdir -p $(OBJS_DR)

$(ARCHIVE)	:	$(OBJS)
	@$(AR) $(ARCHIVE) $(OBJS)

#  ========================  #
#		  CLEANING			 #
#  ========================  #
clean	:
	@$(RM) $(OBJS_DR)

fclean	:	clean
	@$(RM) $(ARCHIVE)

#  ========================  #
#							 #
#  	     -*- END -*-		 #
#							 #
#  ========================	 #