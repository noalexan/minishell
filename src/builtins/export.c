/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:00 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/15 21:20:21 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_export(t_token *token, t_env *env)
{
	t_env	*tmp;
	t_token	*tkn;

	tmp = env;
	tkn = token;
	while (tkn && tmp)
	{
		if (ft_get_var(tkn->content, env) == ft_get_var(tmp->content, env))
		{
			tmp->content = ft_get_content(tkn->content);
			printf("%s\n", token->content);
		}
		tmp = tmp->next;
	}
}
