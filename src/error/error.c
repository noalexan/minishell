/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/11/27 17:30:54 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_export(char *s1, char *s2)
{
	ft_printf(STDERR,
		"\e[31;1m[minishell]: %s: `%s':not a valid identifier\e[0m\n", s1, s2);
	g_minishell.exitcode = 1;
}

int	error_unknown(char *str)
{
	ft_printf(STDERR, "\e[31;1m[minishell]: %s: command not found\e[0m\n", str);
	g_minishell.exitcode = 127;
	return (0);
}

void	error_too_many_args(char *str)
{
	ft_printf(STDERR, "\e[31;1m[minishell]: %s: too many arguments\e[0m\n", str);
	g_minishell.exitcode = 1;
}

void	error_numeric_arg_required(char *s1, char *s2)
{
	ft_printf(STDERR,
		"\e[31;1m[minishell]: %s: %s: numeric argument required \e[0m\n", s1, s2);
	g_minishell.exitcode = 255;
}
