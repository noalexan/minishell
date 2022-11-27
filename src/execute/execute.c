/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:01:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/27 23:07:10 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_convert_env_util(t_env *var)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(var->name, "=");
	tmp2 = ft_strjoin(tmp, var->content);
	free(tmp);
	return (tmp2);
}

char	**ft_convert_env(void)
{
	char	**env;
	t_env	*tmp;
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
		env[++i] = ft_convert_env_util(tmp);
		printf("env: %d: %s\n", i, env[i]);
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
	printf("malloc: %d\n", i + 1);
	tmp = token;
	i = -1;
	while (tmp)
	{
		argv[++i] = ft_strdup(tmp->content);
		printf("argv: %d: %s\n", i, argv[i]);
		tmp = tmp->next;
	}
	return (argv);
}

void	ft_free_execute(char **env, char **argv, char **path)
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
	while (path[++i])
		free(path[i]);
	free(path);
}

char	**ft_get_path(void)
{
	int		i;
	int		j;
	char	**path;

	i = -1;
	path = ft_split(ft_get_var("PATH")->content, ':');
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
		return (cmd);
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

int	ft_execute(t_token *token)
{
	char		**argv;
	char		**env;
	char		**path;
	int			pid;

	// return (0);
	((void) argv, (void) env, (void) path, (void) token);
	env = ft_convert_env();
	argv = ft_convert_argv(token);
	path = ft_get_path();
	free(argv[0]);
	argv[0] = ft_find_path(path, token->content);
	printf("%s\n", argv[0]);
	if (!argv[0])
	{
		ft_free_execute(env, argv, path);
		return (0);
	}
	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, env);
	else if (pid == -1)
		printf("Error while fork\n");
	printf("pid: %d\n", pid);
	waitpid(pid, NULL, 0);
	ft_free_execute(env, argv, path);
	g_minishell.exitcode = 0;
	return (1);
}
