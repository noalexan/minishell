/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:22:12 by Tiplouf           #+#    #+#             */
/*   Updated: 2022/12/20 13:59:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_absolute_path(t_input *s)
{
	if (!access(s->token->content, X_OK))
	{
		if (!access(s->token->content, X_OK))
			s->token->content = ft_strdup_and_free(s->token->content);
		if (opendir(s->token->content))
			(error_not_a_directory("minishell", s->token->content, 2),
				ft_lstclear(s->token), s->token = NULL);
	}
	else if (!access(s->token->content, F_OK))
		(error_permission_denied(s->token->content), ft_lstclear(s->token),
			s->token = NULL);
	else
		(error_not_a_directory("minishell", s->token->content, 3),
			(ft_lstclear(s->token), s->token = NULL));
}

void	ft_search_in_path(t_input *s, char **path)
{
	int		i;
	char	*a;

	i = -1;
	while (path[++i])
	{
		a = ft_strjoin(path[i], s->token->content);
		if (!access(a, X_OK))
		{
			if (!opendir(a))
			{
				free(s->token->content);
				s->token->content = ft_strdup_and_free(a);
				return ;
			}
		}
		else if (!access(a, F_OK))
		{
			error_permission_denied(a);
			(ft_lstclear(s->token), s->token = NULL);
			return ;
		}
		free(a);
	}
	(error_unknown(s->token->content), ft_lstclear(s->token), s->token = NULL);
}

void	ft_check_cmd(t_input *s, char **path)
{
	if (!path || !ft_strncmp(s->token->content, "./", 2)
		|| s->token->content[0] == '/')
		ft_absolute_path(s);
	else if (path)
		ft_search_in_path(s, path);
}

void	ft_verify_cmd(t_input *s, char **path)
{
	char	*a;

	if (s)
	{
		if (s->token)
		{
			a = s->token->content;
			if (ft_strcmp(a, "cd") && strcmp(a, "env") && strcmp(a, "export")
				&& strcmp(a, "pwd") && strcmp(a, "unset") && strcmp(a, "echo")
				&& strcmp(a, "exit"))
				ft_check_cmd(s, path);
		}
		ft_verify_cmd(s->next, path);
	}
}

void	ft_verify(void)
{
	char	**path;
	int		i;

	path = ft_get_path();
	ft_verify_cmd(g_minishell.input, path);
	i = -1;
	if (path)
	{
		while (path[++i])
			free(path[i]);
		free(path);
	}
}
