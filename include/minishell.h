/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noah le BG        #+#    #+#             */
/*   Updated: 2022/11/28 12:35:40 by noalexan         ###   ########.fr       */
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

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define TRUE  1
# define FALSE 0

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
	t_env	*env;
}		t_global;

t_global	g_minishell;

// src/env.c
t_env	*ft_create_env(char	**env);
t_env	*ft_create_env_var(char *name, char *content);
t_env	*ft_get_var(char *name);
char	*ft_get_name(char *str);
char	*ft_get_content(char *str);

// src/history.c
void	ft_sethistory(void);
void	ft_addhistory(const char *str);

// src/minishell.c
char	*ft_makeprompt(char *prompt);
int		ft_minishell(const char *prompt);

// src/lexer.c
t_token	*ft_lexer(char *line);

// src/execution.c
int		ft_execute(t_token *token);

// src/utils.c
int		ft_skip_space(char *line);
t_env	*ft_lstadd_back_env(t_env *new);
t_env	*ft_lstlast_env(void);
int		is_equal(char *str);
t_env	*ft_lstnew_env(void *content);
void	ft_lst_delone_env(t_env *del);
void	ft_replace_segment(char *str, char *seg, int s, int l);

// src/signal.c
void	rl_replace_line(const char *text, int clear_undo);
void	clavier(int sig_num);
void	echo_control_seq(int c);

// src/expender.c
int		ft_expender(char *l, int i);

// src/builtins/echo.c
void	ft_echo(t_token *token);

// src/builtins/env.c
void	env_exp(t_token *token, int e);

// src/builtins/export.c
void	ft_export(t_token *token);
int		parse_export(char *str);

// src/builtins/unset.c
void	ft_lst_delete(t_env *e, char *name);
void	ft_unset(t_token *token);

// src/builtins/cd.c
void	ft_cd(t_token *token);

// src/builtins/exit.c
void	ft_exit(t_token *token);

// src/error/error.c
void	error_export(char *s1, char *s2);
int		error_unknown(char *str);
void	error_too_many_args(char *str);
void	error_numeric_arg_required(char *s1, char *s2);

#endif
