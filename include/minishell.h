/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/14 10:59:39 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>

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
t_env	*ft_get_var(char *name, t_env *env);

// src/minishell.c
char	*ft_makeprompt(char *prompt, t_env *env);
int		ft_minishell(const char *prompt, t_env *env);

// src/lexer.c
t_token	*ft_lexer(char **line, t_env *env);

// src/utils.c
int		ft_skip_space(char *line, int i);

// src/variable.c
char	*ft_variable(char **l, int i, t_env *env);

#endif
