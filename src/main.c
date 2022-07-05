/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/05 12:20:10 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int end;

t_input	parse_input(char *line)
{
	t_input input;

	input.cmds = ft_calloc(1, sizeof(t_cmd));
	input.cmds->cmd = line;
	input.cmds->next = NULL;
	return (input);
}


void	execute(t_input input, char **env)
{
	int	i;

	i = -1;
	if (!strcmp(input.cmds->cmd, "exit"))
		end = 1;
	else if (!strcmp(input.cmds->cmd, "env")
		|| !strcmp(input.cmds->cmd, "ENV"))
		while (env[++i])
			printf("%s\n", env[i]);
	else
		printf("minishell: error: command \"%s\" not found\n", input.cmds->cmd);
	ft_lstclear(input.cmds);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void) argc;
	(void) argv;
	end = 0;
	while (!end)
	{
		line = readline(PROMPT);
		if (line[0])
		{
			add_history(line);
			execute(parse_input(line), env);
		}
		free(line);
	}
	system("leaks minishell");
	return (0);
}
