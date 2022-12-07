/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:01:34 by BEBZ              #+#    #+#             */
/*   Updated: 2022/12/07 23:52:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_input *s)
{
	char		**argv;
	char		**env;
	char		**path;
	int			pid;
	// int			status;

	env = ft_convert_env();
	argv = ft_convert_argv(s->token);
	path = ft_get_path();
	if (!path)
		return (ft_free_execute(env, argv, path));
	free(argv[0]),
	argv[0] = ft_find_path(path, s->token->content);
	if (!argv[0])
		return (ft_free_execute(env, argv, path));
	pid = fork();
	// if (pid > 0)
	// 	waitpid(-1, &status, 0);
	if (pid == 0)
	{
		s->pid = pid;
		(dup2(s->in, 0), dup2(s->out, 1), ft_close_all(g_minishell.input), execve(argv[0], argv, env), exit(1));
	}
	else if (pid == -1)
		printf("Error while fork\n");
	ft_free_execute(env, argv, path);
	g_minishell.exitcode = 0;
	return (1);
}
