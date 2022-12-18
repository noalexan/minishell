/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:39:14 by ple-berr          #+#    #+#             */
/*   Updated: 2022/12/18 19:58:00 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_create_pwd(void)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	buffer[3000];

	pwd = ft_get_var("PWD");
	oldpwd = ft_get_var("OLDPWD");
	if (!pwd)
		pwd = ft_lstadd_back_env(ft_create_env_var(ft_strdup("PWD"), NULL));
	else if (pwd->content)
		free(pwd->content);
	getcwd(buffer, 3000);
	pwd->content = ft_strdup(buffer);
	if (!oldpwd)
		ft_lstadd_back_env(ft_create_env_var(ft_strdup("OLDPWD"), NULL));
	else if (oldpwd->content)
		free(oldpwd->content);
}
