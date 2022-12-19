/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:05:33 by MATHIAS           #+#    #+#             */
/*   Updated: 2022/12/19 19:38:05 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "sys/stat.h"

void	ft_goto(const char *to)
{
	char	buffer[3000];

	if (chdir(to) != 0)
	{
		if (access(to, F_OK) != 0)
			return (error_not_a_directory(to, "cd", 0));
		else
			return (error_not_a_directory("cd", to, 1));
	}
	if (ft_get_var("PWD"))
	{
		if (ft_get_var("OLDPWD"))
			(free(ft_get_var("OLDPWD")->content), ft_get_var("OLDPWD")->content
				= ft_strdup(ft_get_var("PWD")->content));
		(free(ft_get_var("PWD")->content), getcwd(buffer, 3000));
		ft_get_var("PWD")->content = ft_strdup(buffer);
	}
	else if (ft_get_var("OLDPWD"))
	{
		free(ft_get_var("OLDPWD")->content);
		ft_get_var("OLDPWD")->content = ft_strdup("");
	}
}

void	ft_goto_home(void)
{
	t_env	*pwd;

	pwd = ft_get_var("PWD");
	if (ft_get_var("HOME"))
	{
		chdir(ft_get_var("HOME")->content);
		if (pwd)
		{
			if (ft_get_var("OLDPWD"))
			{
				free(ft_get_var("OLDPWD")->content);
				ft_get_var("OLDPWD")->content = ft_strdup(pwd->content);
			}
			free(pwd->content);
			pwd->content = ft_strdup(ft_get_var("HOME")->content);
		}
		else if (ft_get_var("OLDPWD"))
		{
			free(ft_get_var("OLDPWD")->content);
			ft_get_var("OLDPWD")->content = ft_strdup("");
		}
	}
	else
		error_cd_home_not_set();
}

void	ft_cd(t_token *t)
{
	if (t)
		ft_goto(t->content);
	else
		ft_goto_home();
}
