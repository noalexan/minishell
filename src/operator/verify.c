/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:22:12 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/03 22:50:24 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_verify_cmd(t_input *s, char **path)
{
	char	*cmd_path;
	char	*a;

	if (s)
	{
		a = s->token->content;
		cmd_path = ft_find_path(path, a);
		if (!cmd_path && ft_strcmp(a, "echo") && strcmp(a, "env")
			&& strcmp(a, "export") && strcmp(a, "unset") && strcmp(a, "cd")
			&& strcmp(a, "pwd") && strcmp(a, "exit")
			&& /* DEBUG */ strcmp(a, "leaks") && strcmp(a, "heredoc") && strcmp(a, "re") && strcmp(a, "fre") && strcmp(a, "history-fd") && strcmp(a, "colors"))
		{
			error_unknown(a);
			free(cmd_path);
			ft_verify_cmd(s->next, path);
			return (0);
		}
		free(cmd_path);
		return (ft_verify_cmd(s->next, path));
	}
	return (1);
}

void	ft_verify(void)
{
	char	**path;
	int		i;

	path = ft_get_path();
	if (!ft_verify_cmd(g_minishell.input, path))
	{
		ft_clear(g_minishell.input);
		g_minishell.input = NULL;
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
