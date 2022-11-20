/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:00 by Tac               #+#    #+#             */
/*   Updated: 2022/11/20 12:17:21 by mayoub           ###   ########.fr       */
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
		if ((str[i] >= 0 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 60)
			|| (str[i] >= 62 && str[i] <= 64)
			|| (str[i] >= 123 && str[i] <= 127))
			return (0);
		i++;
	}
	return (1);
}

void	ft_export(t_token *token, t_env *env)
{
	t_env	*tmp;
	t_token	*tkn;
	char	*str;

	tmp = env;
	tkn = token;
	while (env)
	{
		if (!parse_export(token->content))
			return (error_export(token->content));
		str = ft_get_name(token->content);
		if (!ft_strcmp(str, env->name)
			&& is_equal(token->content) && env->type == 1)
		{
			free(env->content);
			env->content = ft_get_content(token->content);
		}
		free(str);
		env = env->next;
		if (token->next)
			ft_export(token->next, env);
	}
	env = tmp;
}
