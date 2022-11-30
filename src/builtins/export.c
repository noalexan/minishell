/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:00 by Tac               #+#    #+#             */
/*   Updated: 2022/11/30 12:05:05 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_export(char *str)
{
	int	i;

	i = 1;
	if ((str[0] >= 0 && str[0] <= 64) || str[0] == 91 || str[0] == 93
		|| str[0] == 94 || str[0] == 96 || (str[0] >= 123 && str[0] <= 127))
		return (0);
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || (str[i] >= 35 && str[i] <= 47)
			|| (str[i] >= 58 && str[i] <= 60)
			|| (str[i] >= 62 && str[i] <= 64)
			|| (str[i] >= 123 && str[i] <= 127) || (str[i] == 33))
			return (0);
		i++;
	}
	return (1);
}

void	ft_export(t_token *token)
{
	t_env	*v;
	char	*n;
	char	*content;

	if (token)
	{
		if (!parse_export(token->content))
			return (error_export("export", token->content),
				ft_export(token->next));
		n = ft_get_name(token->content);
		content = ft_get_content(token->content);
		v = ft_get_var(n);
		if (v && content != NULL)
			free(v->content);
		else if (!v)
			v = ft_lstadd_back_env(ft_create_env_var(ft_strdup(n), NULL));
		if (content && v)
			v->content = ft_strdup(content);
		else if (content != NULL && v)
			v->content = ft_strdup("");
		(free(content), free(n), ft_export(token->next));
	}
}
