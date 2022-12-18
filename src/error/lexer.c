/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:17:50 by amogus            #+#    #+#             */
/*   Updated: 2022/12/18 20:00:05 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_error_syntax(t_token *t)
{
	ft_putendl_fd("\e[31;1m[minishell]: Error syntax\e[0m", STDERR);
	ft_lstclear(t);
	g_minishell.exitcode = 127;
	return (NULL);
}
