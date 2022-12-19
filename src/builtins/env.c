/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:20:14 by mhug              #+#    #+#             */
/*   Updated: 2022/12/19 19:37:31 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	env_exp(t_input *s, int e)
{
	t_env	*tmp;

	tmp = g_minishell.env;
	if (e == 2 && s->token->next)
		return (ft_unset(s->token->next));
	else if (e == 1 && s->token->next)
		return (ft_export(s->token->next));
	else if (e == 0 && s->token->next)
		return (error_not_a_directory("env", s->token->next->content, 3));
	if (fork() == 0)
	{
		(dup2(s->in, 0), dup2(s->out, 1), ft_close_all(g_minishell.input));
		while (tmp)
		{
			if (e == 1 && tmp->content == NULL)
				printf("declare -x %s\n", tmp->name);
			else if (e == 1 && tmp->content)
				printf("declare -x %s=\"%s\"\n", tmp->name, tmp->content);
			else if (e == 0 && tmp->content)
				printf("%s=%s\n", tmp->name, tmp->content);
			tmp = tmp->next;
		}
		exit(0);
	}
}
