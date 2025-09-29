/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:32:57 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 06:26:33 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ======================== */
/*		 DEFINITIONS		*/
/* ======================== */
#ifndef MINISHELL_H
# define MINISHELL_H

# define BBLU "\033[1;34m"
# define RST "\033[0m"

# define _DEFAULT_SOURCE

# define SYNTAX_ERR -1
# define MALC_FAIL 42
# define SUCCESS 0

/* ====================== */
/*		  INCLUDES		  */
/* ====================== */
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"

/* ======================== */
/*	   STRUCTS & ENUMS		*/
/* ======================== */
extern volatile sig_atomic_t	g_sig;
typedef struct s_tokens			t_tkns;
typedef struct s_redir			t_redir;
typedef struct s_shell			t_shell;
typedef struct s_cmd			t_cmd;
typedef enum e_rdr				t_rdr;
typedef enum e_tk				t_tk;

enum e_tk
{
	T_REDIR_OUT,
	T_REDIR_IN,
	T_HEREDOC,
	T_APPEND,
	T_DOUBLE,
	T_SINGLE,
	T_WORD,
	T_PIPE,
};

enum e_rdr
{
	HEREDOC,
	APPEND,
	OUT,
	IN
};

struct s_tokens
{
	bool	is_not_mergable;
	bool	is_expand;
	char	*value;
	t_tkns	*next;
	t_tk	type;
};

struct s_redir
{
	char	*filename;
	int		doc_fd;
	t_rdr	type;
};

struct s_cmd
{
	int		redir_count;
	int		word_count;
	char	*cmd_path;
	int		fds[2];
	char	**args;
	t_redir	*redir;
	t_cmd	*next;
	pid_t	pid;
};

struct s_shell
{
	pid_t	last_cmd_pid;
	char	*cmd_line;
	int		cmd_count;
	t_tkns	*tokens;
	char	*expand;
	char	**envp;
	t_cmd	*cmds;
	t_tkns	*last;
	int		exit;
	char	**av;
	int		ac;
};

/* ======================== */
/*		PARSING FUNCS		*/
/* ======================== */
int		add_redir_cmd(t_cmd *cmd, t_tkns **tokens, int *rdr_i, t_shell *sh);
int		create_var(t_shell *sh, char c, char *key, bool is_special);
int		add_word_cmd(t_cmd *cmd, const char *token, int *wrd_i);
int		syntax_check(t_tkns *tokens, bool quotes_err);
int		expand_var(t_shell *sh, const char *tk);
int		append_arg(t_shell *sh, char c);
int		tokenizer(t_shell *shell);
int		parsing(t_shell *shell);

char	*append_str(char **env, char *s1, const char *s2, bool is_special);
char	*append_char(char *s, char c);

void	start_shell(t_shell *shell, int argc, char **argv, char **envp);
void	add_token(t_shell *sh, t_tk t_type, char *token, bool exp);
void	add_single_quotes(t_shell *sh, int *indx);
void	add_double_quotes(t_shell *sh, int *indx);
void	add_operator(t_shell *sh, int *indx);
void	add_word(t_shell *sh, int *indx);
void	expander(t_shell *sh);

bool	is_closed_quotes(const char *input, int loc);

t_cmd	*init_cmd(t_shell *sh, t_tkns *tokens);
t_cmd	*get_last_cmd(t_cmd *cmd);

/* ======================== */
/*		 UTILS FUNCS		*/
/* ======================== */
void	clean_shell(t_shell *shell, int status);
void	update_shlvl(t_shell *sh, char **shlvl);
void	update_key(char **key, const char *var);
void	split_var(t_shell *sh, t_tkns *curr);
void	set_var(t_shell *sh, const char *var);
void	check_empty_expansions(t_shell *sh);
void	parent_exec_sigquit(int sig);
void	clean_tokens(t_tkns *head);
void	close_and_wait(t_shell *sh);
void	parent_exec_sigint(int sig);
void	merge_tokens(t_shell *sh);
void	prompt_sigint(int signum);
void	parent_exec_signals(void);
void	swap(char **a, char **b);
void	clean_cmds(t_cmd *cmds);
void	clean_strs(char **strs);
void	close_pair(int fd[2]);
void	prompt_signals(void);
void	doc_sigint(int sig);
void	child_signals(void);
void	doc_signals(void);
void	close_fds(void);
int		update_env(t_shell *sh, const char *var, char ***new_env);
int		open_doc(t_tkns *delim, t_shell *shell);
int		copy_env(char **dest, char **envp);
int		count_env_entries(char **envp);
int		skip_whitesp(const char *s);
int		is_oper(char c);

char	*ret_fail(char **paths, char *arg, t_shell *sh);
char	*get_env_value(const char *key, char **envp);
char	*resolve_path(char *cmd0, t_shell *shell);

char	**get_env_key(t_shell *sh, const char *key);

bool	is_parent_builtin(const char *cmd);
bool	is_valid_key(const char *name);
bool	is_redir(const char *token);
bool	is_empty(const char *line);
bool	is_pipe(const char *token);
bool	is_not_mergable(char c);
bool	is_word(char token);
bool	is_var(char var);

t_tkns	*get_last_token(t_tkns *tokens);
t_tkns	*create_token(char *val);

t_tk	get_opertype(const char *s);

/* ======================== */
/*	   EXECUTION FUNCS		*/
/* ======================== */
int		open_dup_fds(int fd_in, int fd_out, t_shell *sh, t_cmd *cmd);
int		child_fork(t_cmd *cmd, t_cmd *prev, t_shell *sh);

void	child_exec(t_shell *sh, t_cmd *curr, t_cmd *prev);
void	cmd_exec(t_cmd *agv, t_shell *shell);
void	execution(t_shell *sh);

/* ======================== */
/*	   BUILT-INS FUNCS		*/
/* ======================== */
int		export_cmd(char **args, t_shell *shell);
int		unset_cmd(char **args, t_shell *shell);
int		built_ins(t_cmd *cmd, t_shell *shell);
int		env_cmd(t_shell *shell, t_cmd *cmd);
int		cd_cmd(char **av, t_shell *sh);
int		echo_cmd(char **cmd);
int		pwd_cmd(t_shell *sh);

void	exit_cmd(t_cmd *cmd, t_shell *shell);

#endif