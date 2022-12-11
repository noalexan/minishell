/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:05:33 by MATHIAS           #+#    #+#             */
/*   Updated: 2022/12/10 10:34:42 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "sys/stat.h"

void	old_pwd(void)
{
	t_env	*pwd;
	t_env	*tmp;

	pwd = g_minishell.env;
	tmp = g_minishell.env;
	while (ft_strcmp(g_minishell.env->name, "OLDPWD") && g_minishell.env)
		g_minishell.env = g_minishell.env->next;
	while (ft_strcmp(pwd->name, "PWD") && pwd)
		pwd = pwd->next;
	free(g_minishell.env->content);
	g_minishell.env->content = ft_strdup(pwd->content);
	g_minishell.env = tmp;
}

void	ft_cd(t_token *token)
{
	char	*b;

	b = ft_calloc(3000, sizeof(char));
	if (token && token->content && token->content[0] && g_minishell.env)
	{
		if (1)
		{
			if (chdir(token->content) != 0)
			{
				if (access(token->content, F_OK) != 0)
					return (error_not_a_directory(token->content, 0), free(b));
				else
					return (error_not_a_directory(token->content, 1), free(b));
			}
			if (ft_get_var("PWD"))
			{
				(old_pwd(), free(ft_get_var("PWD")->content), getcwd(b, 3000));
				ft_get_var("PWD")->content = ft_strdup_and_free(b);
			}
			else
				free(b);
		}
	}
	g_minishell.exitcode = 0;
}
