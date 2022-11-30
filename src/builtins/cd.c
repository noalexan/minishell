/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:05:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/30 09:54:32 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "sys/stat.h"

void	ft_cd(t_token *token)
{
	char	*buf;

	buf = ft_calloc(3000, sizeof(char));
	if (token && token->content && token->content[0] && g_minishell.env)
	{
		if (1)
		{
			if (chdir(token->content) != 0)
			{
				if (access(token->content, F_OK) != 0)
					return (error_not_a_directory(token->content, 0));
				else
					return (error_not_a_directory(token->content, 1));
			}
			free(ft_get_var("PWD")->content);
			getcwd(buf, 3000);
			ft_get_var("PWD")->content = ft_strdup_and_free(buf);
		}
	}
	else
		free(buf);
	g_minishell.exitcode = 0;
}
