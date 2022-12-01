/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noah le BG        #+#    #+#             */
/*   Updated: 2022/12/01 22:50:26 by noalexan         ###   ########.fr       */
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
	t_input	*input;
	t_env	*env;
}		t_global;

t_global	g_minishell;

// src/🤖.c
char	*ft_makeprompt(char *prompt);
int		ft_minishell(const char *prompt);

// src/env.c
t_env	*ft_create_env(char	**env);
t_env	*ft_create_env_var(char *name, char *content);
t_env	*ft_get_var(char *name);
char	*ft_get_name(char *str);
char	*ft_get_content(char *str);

// src/history.c
void	ft_sethistory(void);
void	ft_addhistory(const char *str);

// src/utils.c
int		ft_skip_space(char *line);
int		is_equal(char *str);
t_env	*ft_lstnew_env(void *content);
void	ft_lst_delone_env(t_env *del);

// src/signal.c
void	rl_replace_line(const char *text, int clear_undo);
void	clavier(int sig_num);
void	echo_control_seq(int c);

// src/operator/lexer.c
void	*ft_lexer(char *line);

// src/operator/expender.c
void	ft_expender(void);

// src/operator/pipe.c
void	ft_pipe(t_token *t);

#endif
