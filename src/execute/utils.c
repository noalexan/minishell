/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:57:28 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/03 22:59:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_convert_env(void)
{
	char	**env;
	t_env	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		i;

	i = 0;
	tmp = g_minishell.env;
	while (tmp && ++i)
		tmp = tmp->next;
	tmp = g_minishell.env;
	printf("calloc: i: %d\n", i);
	env = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		tmp2 = ft_strjoin(tmp->name, "=");
		tmp3 = ft_strjoin(tmp2, tmp->content);
		free(tmp2);
		env[++i] = tmp3;
		tmp = tmp->next;
	}
	return (env);
}

char	**ft_convert_argv(t_token *token)
{
	char	**argv;
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp && ++i)
		tmp = tmp->next;
	argv = ft_calloc(i + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	tmp = token;
	i = -1;
	while (tmp)
	{
		argv[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (argv);
}

int	ft_free_execute(char **env, char **argv, char **path)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
	i = -1;
	if (path)
	{
		while (path[++i])
			free(path[i]);
		free(path);
	}
	return (0);
}

char	**ft_get_path(void)
{
	int		i;
	int		j;
	char	**path;
	t_env	*tmp;

	tmp = ft_get_var("PATH");
	if (!tmp)
		return (NULL);
	i = -1;
	path = ft_split(tmp->content, ':');
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

char	*ft_find_path(char **path, char *cmd)
{
	int		i;
	char	*path_cmd;

	i = -1;
	if (!access(cmd, 00100))
		return (ft_strdup(cmd));
	else
	{
		while (path[++i])
		{
			path_cmd = ft_strjoin(path[i], cmd);
			if (!access(path_cmd, 00100))
				return (path_cmd);
			free(path_cmd);
		}
	}
	return (NULL);
}
