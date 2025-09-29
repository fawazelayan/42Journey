#  ========================  #
#							 #
#  	   -*- MINISHELL -*-	 #
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
NAME		=	minishell

LIB			=	lib
LIBFT_DR	=	libft
SRCS_DR		=	srcs
OBJS_DR		=	objs
INC_DR		=	incs

LIBFT_INC	=	$(LIB)/$(LIBFT_DR)/$(INC_DR)

#  ========================  #
#	      COMMANDS			 #
#  ========================  #
MAKE	=	make -s -C
RM		=	rm -rf

#  ========================  #
#		FILES AND PATHS		 #
#  ========================  #
SRCS	= \
		$(SRCS_DR)/start_shell.c				\
		$(SRCS_DR)/main.c						\
\
		$(SRCS_DR)/parsing/syntax_check.c		\
		$(SRCS_DR)/parsing/tokens_add.c			\
		$(SRCS_DR)/parsing/tokenizer.c			\
		$(SRCS_DR)/parsing/expander.c			\
		$(SRCS_DR)/parsing/parsing.c			\
		$(SRCS_DR)/parsing/heredoc.c			\
\
		$(SRCS_DR)/utils/tokens_add_utils.c		\
		$(SRCS_DR)/utils/tokenizer_utils.c		\
		$(SRCS_DR)/utils/execution_utils.c		\
		$(SRCS_DR)/utils/expander_utils.c		\
		$(SRCS_DR)/utils/signals_utils.c		\
		$(SRCS_DR)/utils/parsing_utils.c		\
		$(SRCS_DR)/utils/tokens_edits.c			\
		$(SRCS_DR)/utils/export_utils.c			\
		$(SRCS_DR)/utils/env_utils.c			\
		$(SRCS_DR)/utils/signals.c				\
		$(SRCS_DR)/utils/clean.c				\
		$(SRCS_DR)/utils/utils.c				\
\
		$(SRCS_DR)/execution/exec_childs.c		\
		$(SRCS_DR)/execution/execution.c		\
		$(SRCS_DR)/execution/dup_open.c			\
\
		$(SRCS_DR)/execution/builtins/export.c	\
		$(SRCS_DR)/execution/builtins/unset.c	\
		$(SRCS_DR)/execution/builtins/exit.c	\
		$(SRCS_DR)/execution/builtins/echo.c	\
		$(SRCS_DR)/execution/builtins/pwd.c		\
		$(SRCS_DR)/execution/builtins/env.c		\
		$(SRCS_DR)/execution/builtins/cd.c		\

OBJS	=	$(patsubst $(SRCS_DR)/%.c,$(OBJS_DR)/%.o,$(SRCS))

LIBFT	=	$(LIB)/$(LIBFT_DR)/libft.a

#  ========================  #
#	  COMPILATION RULES		 #
#  ========================  #
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror \
			-I$(LIBFT_INC) \
			-I$(INC_DR)

RLFLAGS	=	-lreadline

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
#		   BUILDING			 #
#  ========================  #
$(NAME)		:	$(LIBFT) $(OBJS)
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(PURPLE)🔗 Creating SHELLX...\n$(RESET)"; \
	fi
	@$(CC) $(CFLAGS) $(OBJS) \
	$(LIBFT) $(RLFLAGS) -o $(NAME)


$(LIBFT)	:
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(GREEN)\n📦 Creating Libft...$(RESET)"; \
	else \
		echo "$(GREEN)\n🔄 Rebuilding everything...$(RESET)\n"; \
	fi
	@$(MAKE) $(LIB)/$(LIBFT_DR)

#  ========================  #
#		   CLEANING			 #
#  ========================  #
clean	:
	@if [ "$(MAKECMDGOALS)" != "fclean" ] && [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n🧹 Cleaning object files...\n$(RESET)"; \
	fi
	@$(RM) $(OBJS_DR)
	@$(MAKE) $(LIB)/$(LIBFT_DR) clean

fclean	:	clean
	@if [ "$(MAKECMDGOALS)" != "re" ]; then \
		echo "$(RED)\n💥 Cleaning everything...\n$(RESET)"; \
	fi
	@$(RM) $(NAME)
	@$(MAKE) $(LIB)/$(LIBFT_DR) fclean

#  ========================  #
#							 #
#		 -*- END -*-		 #
#							 #
#  ========================	 #