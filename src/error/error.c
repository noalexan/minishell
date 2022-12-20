/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/12/20 08:00:01 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*error_permission_denied(char *str)
{
	(ft_putstr_fd("\e[31;1m[minishell]: ", STDERR), ft_putstr_fd(str, STDERR));
	(ft_putendl_fd(": Permission denied\e[0m", STDERR));
	return (g_minishell.exitcode = 126, NULL);
}

void	error_cd_home_not_set(void)
{
	ft_putstr_fd("\e[31;1m[minishell]: cd: HOME not set\e[0m\n", STDERR);
	g_minishell.exitcode = 1;
}

void	error_export(const char *s1, const char *s2)
{
	(ft_putstr_fd("\e[31;1m[minishell]: ", STDERR), ft_putstr_fd(s1, STDERR));
	(ft_putstr_fd(": `", STDERR), ft_putstr_fd(s2, STDERR));
	ft_putendl_fd("': not a valid identifier\e[0m", STDERR);
	g_minishell.exitcode = 1;
}

int	error_unknown(const char *str)
{
	(ft_putstr_fd("\e[31;1m[minishell]: ", STDERR), ft_putstr_fd(str, STDERR));
	ft_putendl_fd(": command not found\e[0m", STDERR);
	g_minishell.exitcode = 127;
	return (0);
}

void	error_not_a_directory(const char *s, const char *c, int b)
{
	if (b == 1)
	{
		(ft_putstr_fd("\e[31;1m[minishell]: ", STDERR), ft_putstr_fd(s, STDERR));
		(ft_putstr_fd("\e[31;1m: ", STDERR), ft_putstr_fd(c, STDERR));
		ft_putendl_fd(": Not a directory\e[0m", STDERR);
	}
	else if (!b)
	{
		(ft_putstr_fd("\e[31;1m[minishell]: ", STDERR), ft_putstr_fd(c, STDERR));
		(ft_putstr_fd("\e[31;1m: ", STDERR), ft_putstr_fd(s, STDERR));
		ft_putendl_fd(": No such file or directory\e[0m", STDERR);
	}
	else if (b == 2)
	{
		(ft_putstr_fd("\e[31;1m[", STDERR), ft_putstr_fd(s, STDERR));
		(ft_putstr_fd("\e[31;1m]: ", STDERR), ft_putstr_fd(c, STDERR));
		ft_putendl_fd(": is a directory\e[0m", STDERR);
	}
	else if (b == 3)
	{
		(ft_putstr_fd("\e[31;1m[", STDERR), ft_putstr_fd(s, STDERR));
		(ft_putstr_fd("\e[31;1m]: ", STDERR), ft_putstr_fd(c, STDERR));
		ft_putendl_fd(": No such file or directory\e[0m", STDERR);
	}
	g_minishell.exitcode = 1;
}
