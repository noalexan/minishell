/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:01:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/25 16:36:34 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

	i = -1;
	tmp = token;
	while (tmp && ++i)
		tmp = tmp->next;
	argv = ft_calloc(i + 1, sizeof(char *));
	tmp = token;
	while (tmp)
	{
		argv[++i] = ft_strdup(tmp->content);
		printf("argv: %d: %s\n", i, argv[i]);
		tmp = tmp->next;
	}
	return (argv);
}

int	ft_execute(t_token *token)
{
	char	**argv;
	char	**env;

	return (0);
	env = ft_convert_env();
	argv = ft_convert_argv(token);
	execve("/bin/ls", argv, env);
	return (1);
}
