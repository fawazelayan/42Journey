#  ========================  #
#							 #
#  	   -*- MINITALK -*-	 	 #
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
NAME_C		=	$(EXE_DR)/client
NAME_S		=	$(EXE_DR)/server

EXE_DR		=	exe
LIB			=	lib
LIBFT_DR	=	libft
PRINTF_DR	=	printf
SRCS_DR		=	srcs
OBJS_DR		=	objs
INC_DR		=	incs

LIBFT_INC	= $(LIB)/$(LIBFT_DR)/$(INC_DR)
PRINTF_INC	= $(LIB)/$(PRINTF_DR)/$(INC_DR)

#  ========================  #
#	      COMMANDS			 #
#  ========================  #
MAKE	=	make -s -C
RM		=	rm -rf

#  ========================  #
#		FILES AND PATHS		 #
#  ========================  #
SRCS_C	=	$(SRCS_DR)/client.c
SRCS_S	=	$(SRCS_DR)/server.c
OBJS_C	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS_C))
OBJS_S	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS_S))

LIBFT	=	$(LIB)/$(LIBFT_DR)/libft.a
PRINTF	=	$(LIB)/$(PRINTF_DR)/printf.a

#  ========================  #
#	   COMPILATION RULES	 #
#  ========================  #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror \
			-I$(LIBFT_INC) \
			-I$(PRINTF_INC) \
			-I$(INC_DR)

#  ========================  #
#			RULES			 #
#  ========================  #
all		:	$(NAME_C) $(NAME_S) 

re		:	fclean all

.PHONY	:	all clean fclean re

# Compile .o files into objs/
$(OBJS_DR)/%.o			:	$(SRCS_DR)/%.c	| $(OBJS_DR)
	@$(CC) $(CFLAGS) -c $< -o $@

#  ========================  #
#		  BUILDING			 #
#  ========================  #

$(OBJS_DR)	:
	@mkdir -p $(OBJS_DR)


$(EXE_DR)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)📂 Creating executable directory...$(RESET)"; \
	fi
	@mkdir -p $(EXE_DR)


$(NAME_C)	:	$(LIBFT) $(PRINTF) $(OBJS_C) | $(EXE_DR)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating client executable...$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS_C) \
	$(LIBFT) $(PRINTF) -o $(NAME_C)


$(NAME_S)	:	$(LIBFT) $(PRINTF) $(OBJS_S) | $(EXE_DR)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating server executable...\n$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS_S) \
	 $(LIBFT) $(PRINTF) -o $(NAME_S)


$(LIBFT)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)\n📦 Creating Libft...$(RESET)"; \
	else \
		echo "$(GREEN)\n🔄 Rebuilding everything...$(RESET)\n"; \
	fi
	@$(MAKE) $(LIB)/$(LIBFT_DR)


$(PRINTF)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)📦 Creating Printf...$(RESET)"; \
	fi
	@$(MAKE) $(LIB)/$(PRINTF_DR)

#  ========================  #
#		  CLEANING			 #
#  ========================  #
clean	:
	@if [ "$(MAKECMDGOALS)" != "fclean" ] && [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n🧹 Cleaning object files...\n$(RESET)"; \
	fi
	@$(RM) $(OBJS_DR)
	@$(MAKE) $(LIB)/$(LIBFT_DR) clean
	@$(MAKE) $(LIB)/$(PRINTF_DR) clean

fclean	:	clean
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n💥 Cleaning everything...\n$(RESET)"; \
	fi
	@$(RM) $(EXE_DR)
	@$(MAKE) $(LIB)/$(LIBFT_DR) fclean
	@$(MAKE) $(LIB)/$(PRINTF_DR) fclean

#  ========================  #
#							 #
#  	     -*- END -*-		 #
#							 #
#  ========================	 #