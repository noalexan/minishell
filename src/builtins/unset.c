/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:49:50 by eallouch          #+#    #+#             */
/*   Updated: 2022/12/20 10:33:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_unset_name(char *str)
{
	int		i;
	char	*name;

	i = 1;
	name = ft_get_name(str);
	if ((name[0] >= 0 && name[0] <= 64) || name[0] == 91 || name[0] == 93
		|| name[0] == 94 || name[0] == 96 || (name[0] >= 123 && name[0] <= 127))
	{
		(error_export("unset", str), free(name));
		return (0);
	}
	while (name[i])
	{
		if ((name[i] >= 0 && name[i] <= 32) || (name[i] >= 35 && name[i] <= 47)
			|| (name[i] >= 58 && name[i] <= 60)
			|| (name[i] >= 62 && name[i] <= 64)
			|| (name[i] >= 123 && name[i] <= 127) || (name[i] == 33))
		{
			(error_export("unset", str), free(name));
			return (0);
		}
		i++;
	}
	free(name);
	return (1);
}

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
	t_env	*var;
	char	*name;

	if (token)
	{
		if (!parse_unset_name(token->content)
			|| ft_strchr(token->content, '='))
			return (ft_unset(token->next));
		name = ft_get_name(token->content);
		var = ft_get_var(name);
		free(name);
		if (g_minishell.env)
			ft_lst_delone_env(g_minishell.env, var);
		ft_unset(token->next);
	}
}
