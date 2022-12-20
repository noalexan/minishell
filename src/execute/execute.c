/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:01:34 by BEBZ              #+#    #+#             */
/*   Updated: 2022/12/20 12:53:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_input *s)
{
	char		**argv;
	char		**env;
	int			pid;

	if (!s->token)
		return (0);
	env = ft_convert_env();
	argv = ft_convert_argv(s->token);
	(signal(SIGQUIT, clavier_quit), signal(SIGINT, clavier_int2), pid = fork());
	if (pid == 0)
		((dup2(s->in, 0), dup2(s->out, 1), ft_close_all(g_minishell.input)),
			execve(argv[0], argv, env), exit(1));
	else if (pid == -1)
		printf("Error while fork\n");
	(ft_free_execute(env, argv));
	return (1);
}
