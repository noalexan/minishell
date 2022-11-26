/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:05:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/25 02:49:34 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "sys/stat.h"

void	ft_cd(t_token *token)
{
	char	*buf;

	buf = ft_calloc(3000, sizeof(char));
	if (token && token->content && token->content[0])
	{
		if (1)
		{
			chdir(token->content);
			free(ft_get_var("PWD")->content);
			getcwd(buf, 3000);
			ft_get_var("PWD")->content = ft_strdup_and_free(buf);
		}
	}
	else
		free(buf);
}
