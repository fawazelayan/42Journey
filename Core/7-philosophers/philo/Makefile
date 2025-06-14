#  ========================  #
#							 #
#  	   -*- SO_LONG -*-		 #
#							 #
#  ========================  #

#  ========================  #
#			COLORS			 #
#  ========================  #
RED		=	\033[1;31m
PURPLE	=	\033[1;35m
GREEN	=	\033[1;32m
RESET	=	\033[0m

#  ========================  #
#	    FILE STRUCTURE		 #
#  ========================  #
NAME		=	philo

SRCS_DR		=	srcs
OBJS_DR		=	objs
INC_DR		=	incs

#  ========================  #
#	      COMMANDS			 #
#  ========================  #
RM		=	rm -rf

#  ========================  #
#		FILES AND PATHS		 #
#  ========================  #
SRCS	=	$(shell find $(SRCS_DR) -name '*.c')	# Remove wild cards at campus
OBJS	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS))

#  ========================  #
#	   COMPILATION RULES	 #
#  ========================  #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I$(INC_DR)
#  ========================  #
#			RULES			 #
#  ========================  #
all		:	$(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

# Compile .o files into objs/
$(OBJS_DR)/%.o	:	$(SRCS_DR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

#  ========================  #
#		  BUILDING			 #
#  ========================  #
$(NAME)		:	$(OBJS)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)\n🔗 Creating philo executable...\n$(RESET)"; \
	else \
		echo "$(GREEN)\n🔄 Rebuilding everything...$(RESET)\n"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#  ========================  #
#		  CLEANING			 #
#  ========================  #
clean	:
	@if [ "$(MAKECMDGOALS)" != "fclean" ] && [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n🧹 Cleaning object files...\n$(RESET)"; \
	fi
	@$(RM) $(OBJS_DR)

fclean	:	clean
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n💥 Cleaning everything...\n$(RESET)"; \
	fi
	@$(RM) $(NAME)

#  ========================  #
#							 #
#  	     -*- END -*-		 #
#							 #
#  ========================	 #