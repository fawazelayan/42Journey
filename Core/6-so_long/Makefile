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
NAME		=	so_long

LIB			=	lib
MLX_DIR		=	mlx		# Change to mlx_linux at campus 
LIBFT_DR	=	libft
PRINTF_DR	=	printf
GNL_DR		=	GNL
SRCS_DR		=	srcs
OBJS_DR		=	objs
INC_DR		=	incs

LIBFT_INC	=	$(LIB)/$(LIBFT_DR)/$(INC_DR)
PRINTF_INC	=	$(LIB)/$(PRINTF_DR)/$(INC_DR)
GNL_INC		=	$(LIB)/$(GNL_DR)

#  ========================  #
#	      COMMANDS			 #
#  ========================  #
MAKE	=	make -s -C
RM		=	rm -rf

#  ========================  #
#		FILES AND PATHS		 #
#  ========================  #
SRCS	=	$(shell find $(SRCS_DR) -name '*.c')		# Remove wild cards at campus
OBJS	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS))

LIBFT	=	$(LIB)/$(LIBFT_DR)/libft.a
PRINTF	=	$(LIB)/$(PRINTF_DR)/printf.a
GNL		=	$(LIB)/$(GNL_DR)/get_next_line.c $(LIB)/$(GNL_DR)/get_next_line_utils.c

#  ========================  #
#	   COMPILATION RULES	 #
#  ========================  #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror \
			-I$(LIBFT_INC) \
			-I$(PRINTF_INC) \
			-I$(GNL_INC) \
			-I$(INC_DR) \
			-I$(MLX_DIR)
MLX_LBS	=	-L./$(MLX_DIR) -lmlx -lXext -lX11 -lm -ldl # Change only -L./$(MLX_DIR) to -L$(MLX_DIR)

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
$(NAME)		:	$(LIBFT) $(PRINTF) $(OBJS)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating so_long executable...\n$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS) \
	$(LIBFT) $(PRINTF) $(GNL) \
	$(MLX_LBS) \
	-o $(NAME)


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
	@$(RM) $(NAME)
	@$(MAKE) $(LIB)/$(LIBFT_DR) fclean
	@$(MAKE) $(LIB)/$(PRINTF_DR) fclean

#  ========================  #
#							 #
#  	     -*- END -*-		 #
#							 #
#  ========================	 #