/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/27 09:46:16 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "libft.h"
# include "ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TRUE 1
# define FALSE 0

int		g_out;

# define ACCESS_RIGHT 0

# define PROMPT "\033[1;33mminishell polnareff\033[0m> "
# define ERR_NO_CMD "minishell: \e[1;31merror\e[0m: command \"%s\" not found\n"

// Lexer
void	ft_lexer(t_input *input, char *line);
char	*ft_getstr(char *line);
char	*ft_redirection(t_input *input, char *line);

// Utils
char	*ft_skip_space(char *line);
char	*ft_skip_word(char *line);
int		quote(int value, char *line);
int		ft_heredoc(char *limiter);

// Builtins
void	ft_exit(t_input *input);

#endif
