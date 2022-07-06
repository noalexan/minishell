/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:17:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/06 13:18:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**set_slash(char **path)
{
	int	i;
	int	j;

	i = -1;
	while (path[++i])
	{
		j = -1;
		while (path[i][++j])
			;
		if (path[i][j - 1] != '/')
			path[i][j] = '/';
	}
	return (path);
}

char	*find_path(char *cmd)
{
	int		i;
	char	**path;
	char	*path_cmd;

	i = -1;
	path = set_slash(ft_split(getenv("PATH"), ':'));
	while (path[++i])
	{
		path_cmd = ft_strjoin(path[i], cmd);
		if (!access(path_cmd, ACCESS_RIGHT))
		{
			i = -1;
			while (path[++i])
				free(path[i]);
			free(path);
			return (path_cmd);
		}
		free(path_cmd);
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	ft_printf(2, ERR_NO_CMD, cmd);
	return (NULL);
}
