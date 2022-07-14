/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/14 15:51:09 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TRUE 1
# define FALSE 0

# define ACCESS_RIGHT 0

# define PROMPT "\033[1;33mminishell polnareff\033[0m> "
# define ERR_NO_CMD "minishell: \e[1;31merror\e[0m: command \"%s\" not found\n"

t_input	parse(char **split);
char	**set_slash(char **path);
char	*find_path(char *cmd);

#endif
