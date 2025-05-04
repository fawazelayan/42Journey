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
SRCS	=	$(wildcard $(SRCS_DR)/*.c)
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