/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:57:28 by Moulinette        #+#    #+#             */
/*   Updated: 2022/12/20 12:54:22 by mayoub           ###   ########.fr       */
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

int	ft_free_execute(char **env, char **argv)
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
