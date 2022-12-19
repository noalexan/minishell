/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:22:58 by RedBull           #+#    #+#             */
/*   Updated: 2022/12/19 13:20:52 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_error_redirection_nl(void)
{
	ft_putstr_fd(
		"\e[31;1m[minishell]: syntax error near unexpected token `newline'\e[0m\n",
		STDERR);
	ft_clear(g_minishell.input);
	g_minishell.exitcode = 258;
	return (NULL);
}

void	*ft_error_redirection(const char c)
{
	ft_putstr_fd("\e[31;1m[minishell]: syntax error near unexpected token `",
		STDERR);
	ft_putstr_fd((char []){c, 0}, STDERR);
	ft_putendl_fd("'\e[0m", STDERR);
	ft_clear(g_minishell.input);
	g_minishell.exitcode = 258;
	return (NULL);
}

void	*ft_error_fd(void)
{
	ft_putendl_fd("\e[31;1m[minishell]: error while open or pipe\e[0m", STDERR);
	ft_clear(g_minishell.input);
	g_minishell.exitcode = 258;
	return (NULL);
}

void	*ft_error_no_file(const char *s)
{
	ft_putstr_fd("\e[31;1m[minishell]: ", STDERR);
	ft_putstr_fd(s, STDERR);
	ft_putendl_fd(": no such file or directory\e[0m", STDERR);
	g_minishell.exitcode = 1;
	ft_clear(g_minishell.input);
	return (NULL);
}
