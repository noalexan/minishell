/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:22:12 by Tiplouf           #+#    #+#             */
/*   Updated: 2022/12/19 18:22:23 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_verify_cmd(t_input *s, char **path)
{
	char	*cdph;
	char	*a;

	if (s)
	{
		if (!s->token)
			return (0);
		a = s->token->content;
		if (path)
			cdph = ft_find_path(path, a);
		else
			cdph = ft_calloc(1, sizeof(char));
		if (!cdph && ft_strcmp(a, "echo") && strcmp(a, "env")
			&& strcmp(a, "export") && strcmp(a, "unset") && strcmp(a, "cd")
			&& strcmp(a, "pwd") && strcmp(a, "exit"))
			error_unknown(a);
		free(cdph);
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
		ft_clear(g_minishell.input);
	i = -1;
	if (path)
	{
		while (path[++i])
			free(path[i]);
		free(path);
	}
}
