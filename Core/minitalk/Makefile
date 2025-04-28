# -*- Makefile 

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
CFLAGS		=	-Wall -Werror -Wextra -I$(LIBFT_DR) -I$(PRINTF_DR) -I$(INC_DR)

LIBFT		=	$(LIBFT_DR)/libft.a
PRINTF		=	$(PRINTF_DR)/libftprintf.a

all			:	$(EXE_DR) $(LIBFT) $(PRINTF) $(NAME_C) $(NAME_S) 

%.o 		:	%.c
	@echo "\033[0;35mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXE_DR)	:
	@echo "\033[0;34mMaking executables directory...\033[0m"
	@mkdir -p $(EXE_DR)

$(LIBFT)	:
	@echo "\033[0;32mCompiling Libft...\033[0m"
	@make -s -C $(LIBFT_DR)

$(PRINTF)	:
	@echo "\033[0;32mCompiling ft_printf...\033[0m"
	@make -s -C $(PRINTF_DR)

$(NAME_C)	:	$(OBJS_C)
	@echo "\033[0;34mMaking client executable...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(LIBFT) $(PRINTF)

$(NAME_S)	:	$(OBJS_S)
	@echo "\033[0;34mMaking server executable...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S) $(LIBFT) $(PRINTF)

clean		:
	@echo "\033[0;31mCleaning object files...\033[0m"
	@rm -f $(OBJS_S) $(OBJS_C)
	@make -s -C $(LIBFT_DR) clean
	@make -s -C $(PRINTF_DR) clean

fclean		:	clean
	@echo "\033[0;31mCleaning all...\033[0m"
	@rm -rf $(EXE_DR)
	@make -s -C $(LIBFT_DR) fclean
	@make -s -C $(PRINTF_DR) fclean

re			:	fclean all

.PHONY		:	all clean fclean re