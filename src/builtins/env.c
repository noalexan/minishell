/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:20:14 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/15 21:13:29 by mayoub           ###   ########.fr       */
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
		if (e == 1)
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->content);
		else
			printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}
