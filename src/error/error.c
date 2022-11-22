/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/11/22 20:01:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_export(char *s1, char *s2)
{
	ft_printf(STDERR,
		"\e[31;1m[minishell]: %s: `%s':not a valid identifier\e[0m\n", s1, s2);
}

int	error_unknown(char *str)
{
	ft_printf(STDERR, "\e[31;1m[minishell]: %s: command not found\e[0m\n", str);
	return (0);
}
