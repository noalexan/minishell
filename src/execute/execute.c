/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:01:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/02 16:30:24 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_token *token)
{
	char		**argv;
	char		**env;
	char		**path;
	int			pid;

	env = ft_convert_env();
	argv = ft_convert_argv(token);
	path = ft_get_path();
	if (!path)
		return (ft_free_execute(env, argv, path));
	free(argv[0]),
	argv[0] = ft_find_path(path, token->content);
	printf("%s\n", argv[0]);
	if (!argv[0])
		return (ft_free_execute(env, argv, path));

	// ! deplacer [ci-dessous] dans une fonction
	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, env);
	else if (pid == -1)
		printf("Error while fork\n");
	printf("pid: %d\n", pid);
	
	ft_free_execute(env, argv, path);
	g_minishell.exitcode = 0;
	return (1);
}
