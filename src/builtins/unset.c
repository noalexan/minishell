/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:49:50 by eallouch          #+#    #+#             */
/*   Updated: 2022/12/09 20:09:17 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_lst_delete(t_env *e, char *name)
{
	if (e)
	{
		if (ft_strcmp(e->name, name))
			free(e);
		else
			ft_lst_delete(e, name);
	}
}

void	ft_unset(t_token *token)
{
	t_env	*tmp;
	char	*name;

	if (token)
	{
		if (!parse_export_name(token->content)
			|| ft_strchr(token->content, '='))
			return (e_("unset", token->content),
				ft_unset(token->next));
		name = ft_get_name(token->content);
		tmp = ft_get_var(name);
		if (g_minishell.env)
			(ft_lst_delone_env(tmp), free(name));
	}
}
