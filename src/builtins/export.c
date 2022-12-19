/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:00 by Tac               #+#    #+#             */
/*   Updated: 2022/12/19 19:37:25 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_export_name(char *str)
{
	int		i;
	char	*name;

	i = 1;
	name = ft_get_name(str);
	if ((name[0] >= 0 && name[0] <= 64) || name[0] == 91 || name[0] == 93
		|| name[0] == 94 || name[0] == 96 || (name[0] >= 123 && name[0] <= 127))
	{
		(error_export("export", str), free(name));
		return (0);
	}
	while (name[i])
	{
		if ((name[i] >= 0 && name[i] <= 32) || (name[i] >= 35 && name[i] <= 47)
			|| (name[i] >= 58 && name[i] <= 60)
			|| (name[i] >= 62 && name[i] <= 64)
			|| (name[i] >= 123 && name[i] <= 127) || (name[i] == 33))
		{
			(error_export("export", str), free(name));
			return (0);
		}
		i++;
	}
	free(name);
	return (1);
}

void	ft_export(t_token *token)
{
	t_env	*v;
	char	*n;
	char	*cont;

	if (token)
	{
		n = ft_get_name(token->content);
		cont = ft_get_content(token->content);
		if (!parse_export_name(token->content))
		{
			if (cont)
				free(cont);
			return (ft_export(token->next), free(n));
		}
		v = ft_get_var(n);
		if (v && cont != NULL)
			free(v->content);
		else if (!v)
			v = ft_lstadd_back_env(ft_create_env_var(ft_strdup(n), NULL));
		if (cont && v)
			v->content = ft_strdup(cont);
		else if (cont != NULL && v)
			v->content = ft_strdup("");
		(free(cont), free(n), ft_export(token->next));
	}
}
