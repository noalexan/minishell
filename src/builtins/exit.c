/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:11:59 by M.Chanselme       #+#    #+#             */
/*   Updated: 2022/11/28 13:22:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_token *token)
{
	t_token	*t;
	int		i;

	i = -1;
	if (!token->next)
		(printf("exit\n"), g_minishell.exitcode = 0, exit(0));
	t = token->next;
	while (t->content[++i])
	{
		if (!(t->content[0] >= '0' && t->content[0] <= '9') && !t->content[1])
			(error_numeric_arg_required(token->content, t->content), exit(255));
		if (!(t->content[i] >= '0' && t->content[i] <= '9')
			&& (t->content[i] != '+' && t->content[i] != '-'))
			(error_numeric_arg_required(token->content, t->content), exit(255));
	}
	if (t->next)
		return (error_too_many_args(token->content));
	else
	{
		if ((t->content[0] == 53) || (t->content[0] > 47 && t->content[0] < 58))
			g_minishell.exitcode += (unsigned)ft_atoi(t->content) % 256;
		else if (t->content[0] == '-')
			g_minishell.exitcode -= ((unsigned)ft_atoi(t->content) % 256) * -1;
		exit(g_minishell.exitcode);
	}
}

// fix when not '+' and '-'
