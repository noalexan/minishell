/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/12/04 14:00:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_export(const char *s1, const char *s2)
{
	ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
	ft_putstr_fd(s1, STDERR);
	ft_putstr_fd(": `", STDERR);
	ft_putstr_fd(s2, STDERR);
	ft_putendl_fd("': not a valid identifier\e[0m", STDERR);
	g_minishell.exitcode = 1;
}

void	error_synthax_export(const char c)
{
	ft_putstr_fd("\e[31;1m[minishell]: syntax error near unexpected token `",
		STDERR);
	ft_putstr_fd((const char []){c, 0}, STDERR);
	ft_putendl_fd("'\e[0m", STDERR);
	g_minishell.exitcode = 1;
}

int	error_unknown(const char *str)
{
	ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putendl_fd(": command not found\e[0m", STDERR);
	g_minishell.exitcode = 127;
	return (0);
}

void	error_not_a_directory(const char *str, bool b)
{
	if (b)
	{
		ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putendl_fd(": Not a directory\e[0m", STDERR);
	}
	else
	{
		ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putendl_fd(": No such file or directory\e[0m", STDERR);
	}
	g_minishell.exitcode = 1;
}
