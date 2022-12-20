/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noah le BG        #+#    #+#             */
/*   Updated: 2022/12/20 14:06:22 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <dirent.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# define TRUE  1
# define FALSE 0

# define IN  STDOUT
# define OUT STDIN

# define PROMPT "\e[1;33mminishell polnareff\e[0m> "

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}		t_env;

typedef struct s_global
{
	int		exitcode;
	int		history_fd;
	int		pipe;
	int		heredoc;
	t_input	*input;
	t_env	*env;
}		t_global;

t_global	g_minishell;

// src/🤖.c
void	ft_exec(t_input *s);
char	*ft_makeprompt(char *prompt);
void	ft_clear(t_input *s);
int		ft_minishell(const char *prompt);
void	ft_wait_all(t_input *s);
void	ft_close_all(t_input *s);

// src/env.c
t_env	*ft_create_env(char	**env);
t_env	*ft_create_env_var(char *name, char *content);
t_env	*ft_get_var(char *name);
char	*ft_get_name(char *str);
char	*ft_get_content(char *str);

// src/create_pwd.c
void	ft_create_pwd(void);

// src/history.c
void	ft_sethistory(void);
void	ft_addhistory(const char *str);

// src/signal.c
void	rl_replace_line(const char *text, int clear_undo);
void	clavier_int(int sig_num);
void	clavier_quit(int sig_num);
void	clavier_int2(int sig_num);
void	echo_control_seq(int c);

// src/utils.c
int		ft_skip_space(char *line);
t_env	*ft_lstadd_back_env(t_env *new);
int		is_equal(char *str);
t_env	*ft_lstnew_env(void *content);
void	ft_lst_delone_env(t_env *env, t_env *unset);

// src/pars_arg.c
void	parse_arg(char **argv);

// src/operator/lexer.c
void	ft_lexer(char *line);

// src/operator/expender.c
void	ft_expender(void);
int		ft_replace_seg(t_token *t, const char *seg, int *s);
int		ft_insert_var(t_token *t, int i);

// src/operator/heredoc.c
int		ft_heredoc(char *limiter);

// src/operator/pipe.c
void	ft_pipe(t_token *t);

// src/operator/redirection.c
void	ft_redirection(t_input *s);

// src/operator/utils.c
void	ft_open_file(t_input *s, t_token *t);
int		ft_init_redirection_utils(t_input *s, t_token *t);
void	ft_wait_all(t_input *s);
void	ft_close_all(t_input *s);

// src/operator/verify.c
void	ft_verify(void);

// src/execute/execute.c
int		ft_execute(t_input *s);

// src/execute/utils.c
char	**ft_convert_env(void);
char	**ft_convert_argv(t_token *token);
int		ft_free_execute(char **env, char **argv);
char	**ft_get_path(void);

// src/builtins/echo.c
void	ft_echo(t_token *token);
void	ft_exec_echo(t_input *s);

// src/builtins/env.c
void	env_exp(t_input *s, int e);

// src/builtins/export.c
void	ft_export(t_token *token);
int		parse_export_name(char *str);

// src/builtins//pwd.c
void	ft_exec_pwd(t_input *s);

// src/builtins/unset.c
void	ft_lst_delete(t_env *e, char *name);
void	ft_unset(t_token *token);
int		parse_unset_name(char *str);

// src/builtins/cd.c
void	ft_cd(t_token *token);

// src/builtins/exit.c
void	ft_exit(t_token *token);

// src/error/error.c
void	*error_permission_denied(char *str);
void	error_export(const char *s1, const char *s2);
int		error_unknown(const char *str);
void	error_not_a_directory(const char *s, const char *c, int b);
void	error_cd_home_not_set(void);

// src/error/lexer.c
void	*ft_error_syntax(t_token *t);

// src/error/redirection.c
void	*ft_error_redirection_nl(void);
void	*ft_error_redirection(const char c);
void	*ft_error_fd(void);
void	*ft_error_no_file(const char *s);

// src/fun/the_messager.c
void	the_heredoc_donjon(void);

#endif
