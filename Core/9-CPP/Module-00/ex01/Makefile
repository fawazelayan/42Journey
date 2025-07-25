#  ========================  #
#							 #
#  	   -*- MODULE-00 -*-	 #
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
NAME		=	phonebook

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
SRCS	=	srcs/Contact.cpp srcs/PhoneBook.cpp srcs/Utils.cpp \
			srcs/main.cpp
OBJS	=	$(patsubst $(SRCS_DR)/%.cpp,$(OBJS_DR)/%.o,$(SRCS))

#  ========================  #
#	   COMPILATION RULES	 #
#  ========================  #
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -I$(INC_DR) -std=c++98

#  ========================  #
#			RULES			 #
#  ========================  #
all		:	$(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

# Compile .o files into objs/
$(OBJS_DR)/%.o	:	$(SRCS_DR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

#  ========================  #
#		  BUILDING			 #
#  ========================  #
$(NAME)		:	$(OBJS)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)\n🔗 Creating phonebook executable...\n$(RESET)"; \
	else \
		echo "$(GREEN)\n🔄 Rebuilding everything...$(RESET)\n"; \
	fi
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

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