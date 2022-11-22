/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noah le BG        #+#    #+#             */
/*   Updated: 2022/11/22 19:51:39 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

# include "libft.h"
# include "ft_printf.h"

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define TRUE  1
# define FALSE 0

# define PROMPT "\e[1;33mminishell polnareff\e[0m> "

int	g_exitcode;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}		t_env;

// src/env.c
t_env	*ft_create_env(char	**env);
t_env	*ft_create_env_var(char *name, char *content);
t_env	*ft_get_var(char *name, t_env *env);
char	*ft_get_name(char *str);
char	*ft_get_content(char *str);

// src/minishell.c
char	*ft_makeprompt(char *prompt, t_env *env);
int		ft_minishell(const char *prompt, t_env *env);

// src/lexer.c
t_token	*ft_lexer(char **line, t_env *env);

// src/utils.c
int		ft_skip_space(char *line, int i);
t_env	*ft_lstadd_back_env(t_env **lst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
int		is_equal(char *str);
t_env	*ft_lstnew_env(void *content);
void	ft_free(void *a);
void	ft_lst_delone_env(t_env *env, t_env *del);

// src/signal.c
void	rl_replace_line(const char *text, int clear_undo);
void	clavier(int sig_num);
void	echo_control_seq(int c);

// src/builtins/echo.c
void	ft_echo(t_token *token);

// src/builtins/env.c
void	env_exp(t_token *token, t_env *env, int e);

// src/builtins/export.c
void	ft_export(t_token *token, t_env *env);
int		parse_export(char *str);

// src/builtins/unset.c
void	ft_lst_delete(t_env *e, char *name);
void	ft_unset(t_token *token, t_env *env);

// src/variable.c
char	*ft_variable(char **l, int i, t_env *env);

// src/error/error.c
void	error_export(char *s1, char *s2);
int		error_unknown(char *str);

#endif
