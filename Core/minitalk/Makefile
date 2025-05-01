# -*- Makefile -*-

# COLORS #
RED			=	\033[1;31m
PURPLE		=	\033[1;35m
GREEN		=	\033[1;32m
RESET		=	\033[0m

# COMMANDS #
MAKE		=	make -s -C
RM			=	rm -rf

# EXE NAME #
NAME_C		=	$(EXE_DR)/client
NAME_S		=	$(EXE_DR)/server

# DIRECTORIES #
LIBFT_DR	=	libft
PRINTF_DR	=	ft_printf
SRCS_DR		=	srcs
INC_DR		=	inc
EXE_DR		=	exe

# SOURCE AND OBJECT FILES #
SRCS_C		=	$(SRCS_DR)/client.c
SRCS_S		=	$(SRCS_DR)/server.c
OBJS_C		=	$(SRCS_C:.c=.o)
OBJS_S		=	$(SRCS_S:.c=.o)

# COMPILER AND FLAGS #
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DR)/$(INC_DR) -I$(PRINTF_DR)/$(INC_DR) -I$(INC_DR)

# LIBRARIES #
LIBFT		=	$(LIBFT_DR)/libft.a
PRINTF		=	$(PRINTF_DR)/libftprintf.a

# RULES #
all			:	$(LIBFT) $(PRINTF) $(EXE_DR) $(NAME_C) $(NAME_S) 

%.o			:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)\n📦 Creating Libft...$(RESET)"; \
	else \
		echo "$(GREEN)\n🔄 Rebuilding everything...$(RESET)\n"; \
	fi
	@$(MAKE) $(LIBFT_DR)

$(PRINTF)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)📦 Creating Printf...$(RESET)"; \
	fi
	@$(MAKE) $(PRINTF_DR)

$(EXE_DR)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)📂 Creating executable directory...$(RESET)"; \
	fi
	@mkdir -p $(EXE_DR)

$(NAME_C)		:	$(OBJS_C)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating client executable...$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) $(PRINTF) -o $(NAME_C)

$(NAME_S)		:	$(OBJS_S)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating server executable...\n$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) $(PRINTF) -o $(NAME_S)

clean		:
	@if [ "$(MAKECMDGOALS)" != "fclean" ] && [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n🧹 Cleaning object files...\n$(RESET)"; \
	fi
	@$(RM) $(OBJS_C) $(OBJS_S)
	@$(MAKE) $(LIBFT_DR) clean
	@$(MAKE) $(PRINTF_DR) clean

fclean		:	clean
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n💥 Cleaning everything...\n$(RESET)"; \
	fi
	@$(RM) $(EXE_DR)
	@$(MAKE) $(LIBFT_DR) fclean
	@$(MAKE) $(PRINTF_DR) fclean

re			:	fclean all

.PHONY		: all clean fclean re