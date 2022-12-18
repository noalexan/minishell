/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:39:14 by M.Mongellaz       #+#    #+#             */
/*   Updated: 2022/12/18 19:58:37 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_get_var(char *name)
{
	t_env	*tmp;

	tmp = g_minishell.env;
	if (name)
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, name))
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

t_env	*ft_create_env_var(char *name, char *content)
{
	t_env	*var;

	var = ft_calloc(1, sizeof(t_env));
	var->name = ft_strdup_and_free(name);
	var->content = ft_strdup(content);
	if (content)
		free(content);
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
	if (!str)
		return (NULL);
	name = ft_strldup(str, i);
	return (name);
}

char	*ft_get_content(char *str)
{
	char	*content;
	int		i;

	i = ft_strchr(str, '=') + 1;
	if (i <= 1)
		return (NULL);
	content = ft_strdup(str + i);
	return (content);
}

t_env	*ft_create_env(char **env)
{
	t_env	*lst;
	char	*tmp;

	lst = NULL;
	if (env && env[0])
	{
		tmp = ft_get_name(env[0]);
		if (!ft_strcmp(tmp, "OLDPWD"))
			lst = ft_create_env_var(
					ft_get_name(env[0]), ft_get_content(NULL));
		else
			lst = ft_create_env_var(
					ft_get_name(env[0]), ft_get_content(env[0]));
		free(tmp);
		lst->next = ft_create_env(env + 1);
	}
	return (lst);
}
