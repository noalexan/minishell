/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/11/30 19:03:09 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_export(char *s1, char *s2)
{
	ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
	ft_putstr_fd(s1, STDERR);
	ft_putstr_fd(": `", STDERR);
	ft_putstr_fd(s2, STDERR);
	ft_putendl_fd("':not a valid identifier\e[0m", STDERR);
	g_minishell.exitcode = 1;
}

int	error_unknown(char *str)
{
	ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putendl_fd(": command not found\e[0m", STDERR);
	g_minishell.exitcode = 127;
	return (0);
}

void	error_not_a_directory(char *str, bool b)
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
