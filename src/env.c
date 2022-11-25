/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:39:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/24 23:41:41 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_get_var(char *name)
{
	t_env	*tmp;

	tmp = g_minishell.env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_create_env_var(char *name, char *content)
{
	t_env	*var;

	var = ft_calloc(1, sizeof(t_env));
	var->name = ft_strdup_and_free(name);
	if (content)
		var->content = ft_strdup_and_free(content);
	else
		var->content = NULL;
	var->next = NULL;
	return (var);
}

char	*ft_get_name(char *str)
{
	char	*name;
	int		i;

	i = ft_strchr(str, '=');
	if (!i)
		return (ft_strdup(str));
	name = ft_strldup(str, i);
	return (name);
}

char	*ft_get_content(char *str)
{
	char	*content;
	int		i;

	i = ft_strchr(str, '=') + 1;
	if (i == 1)
		return (NULL);
	content = ft_strdup(str + i);
	return (content);
}

t_env	*ft_create_env(char **env)
{
	t_env	*lst;

	lst = NULL;
	if (env[0])
	{
		lst = ft_create_env_var(
				ft_get_name(env[0]),
				ft_get_content(env[0]));
		lst->next = ft_create_env(env + 1);
	}
	else
		return (NULL);
	return (lst);
}
