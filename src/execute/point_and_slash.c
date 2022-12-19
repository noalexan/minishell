/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_and_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:45:54 by hboukhor          #+#    #+#             */
/*   Updated: 2022/12/19 20:56:37 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_search_in_path(char **path, char *cmd)
{
	int		i;
	char	*path_cmd;

	i = -1;
	while (path[++i])
	{
		path_cmd = ft_strjoin(path[i], cmd);
		if (!access(path_cmd, X_OK))
			return (path_cmd);
		if (!access(path_cmd, F_OK))
			return (error_permission_denied(path_cmd));
		free(path_cmd);
	}
	return (NULL);
}

static char	*ft_absolute_path(char *cmd)
{
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	if (!access(cmd, F_OK))
		return (error_permission_denied(ft_strdup(cmd)));
	return (NULL);
}

char	*ft_find_path(char **path, char *cmd)
{
	if (cmd[0] == '.' || cmd[0] == '/')
		return (ft_absolute_path(cmd));
	else
		return (ft_search_in_path(path, cmd));
}
