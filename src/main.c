/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:46 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	g_end;

void	execute(t_input input, char **env)
{
	if (input.cmds->cmd && !strcmp(input.cmds->cmd, "exit"))
		g_end = TRUE;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "cd"))
		;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "env"))
		;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "pwd"))
		;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "echo"))
		;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "unset"))
		;
	else if (input.cmds->cmd && !strcmp(input.cmds->cmd, "export"))
		;
	else
	{
		if (input.cmds->cmd)
			free(input.cmds->cmd);
	}
	free(input.cmds);
	(void) env;
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	**line_split;
	int		i;

	((void) argc, (void) argv);
	g_end = FALSE;
	while (!g_end)
	{
		i = -1;
		line = readline(PROMPT);
		if (line[0])
		{
			line_split = ft_split(line, ' ');
			if (line_split[0])
			{
				add_history(line);
				execute(parse(line_split), env);
				while (line_split[++i])
					free(line_split[i]);
			}
			free(line_split);
		}
		free(line);
	}
	system("leaks minishell");
	return (0);
}
