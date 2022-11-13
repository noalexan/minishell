/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:39:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/13 17:02:22 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_get_var(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, name))
			return (env->next = NULL);
		env = env->next;
	}
	return (NULL);
}

t_env	*ft_create_env_variable(const char *name, const char *content)
{
	t_env	*var;

	var = ft_calloc(1, sizeof(t_env));
	var->name = ft_strdup(name);
	var->content = ft_strdup(content);
	var->next = NULL;
	return (var);
}

char	*ft_get_name(const char *str)
{
	char	*name;
	int		i;

	i = ft_strchr(str, '=');
	name = ft_strldup(str, i);
	return (name);
}

char	*ft_get_content(const char *str)
{
	char	*content;
	int		i;

	i = ft_strchr(str, '=');
	content = ft_strdup(str + i);
	return (content);
}

t_env	*ft_create_env(char **env)
{
	t_env	*lst;

	lst = NULL;
	if (env[0])
	{
		lst = ft_create_env_variable(ft_get_name(env[0]),
				ft_get_content(env[0]));
		lst->next = ft_create_env(env + 1);
	}
	else
		return (NULL);
	return (lst);
}
