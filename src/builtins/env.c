/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:20:14 by mhug              #+#    #+#             */
/*   Updated: 2022/11/24 23:58:19 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	env_exp(t_token *token, int e)
{
	t_env	*tmp;

	tmp = g_minishell.env;
	if (e == 2 && token->next)
		return (ft_unset(token->next));
	else if (e == 1 && token->next)
		return (ft_export(token->next));
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
}
