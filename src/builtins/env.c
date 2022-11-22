/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:20:14 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/22 14:47:00 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	env_exp(t_token *token, t_env *env, int e)
{
	t_env	*tmp;

	tmp = env;
	if (e == 1 && token->next)
		return (ft_export(token->next, env));
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
