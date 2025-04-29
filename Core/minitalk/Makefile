# -*- Makefile 

RED			=	\033[0;31m
PURPLE		=	\033[0;35m
GREEN		=	\033[0;32m
RESET		=	\033[0m

NAME_S		=	$(EXE_DR)/server
NAME_C		=	$(EXE_DR)/client

LIBFT_DR	=	libft
PRINTF_DR	=	ft_printf
SRCS_DR		=	srcs
INC_DR		=	inc
EXE_DR		=	exe

SRCS_S		=	$(SRCS_DR)/server.c
SRCS_C		=	$(SRCS_DR)/client.c

OBJS_S		=	$(SRCS_S:.c=.o)
OBJS_C		=	$(SRCS_C:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(LIBFT_DR)/inc -I$(PRINTF_DR)/inc -I$(INC_DR)

LIBFT		=	$(LIBFT_DR)/libft.a
PRINTF		=	$(PRINTF_DR)/libftprintf.a


all			:	$(EXE_DR) $(LIBFT) $(PRINTF) $(NAME_C) $(NAME_S) 

%.o			:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXE_DR)	:
	@echo "$(GREEN)\n📂 Making executables directory...$(RESET)"
	@mkdir -p $(EXE_DR)

$(LIBFT)	:
	@echo "$(GREEN)📦 Creating Libft...$(RESET)"
	@make -s -C $(LIBFT_DR)

$(PRINTF)	:
	@echo "$(GREEN)📦 Creating Printf...$(RESET)"
	@make -s -C $(PRINTF_DR)

$(NAME_C)	:	$(OBJS_C)
	@echo "$(PURPLE)🔗 Creating client executable...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(LIBFT) $(PRINTF)

$(NAME_S)	:	$(OBJS_S)
	@echo "$(PURPLE)🔗 Creating server executable...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S) $(LIBFT) $(PRINTF)

clean		:
	@echo "$(RED)\n🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS_S) $(OBJS_C)
	@make -s -C $(LIBFT_DR) clean
	@make -s -C $(PRINTF_DR) clean

fclean		:	clean
	@echo "$(RED)💥 Cleaning all...\n$(RESET)"
	@rm -rf $(EXE_DR)
	@make -s -C $(LIBFT_DR) fclean
	@make -s -C $(PRINTF_DR) fclean

re			:	fclean all

.PHONY		:	all clean fclean re