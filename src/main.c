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

void	execute(char **cmd, char **env)
{
	int	i;

	i = -1;
	if (!strcmp(cmd[0], "exit"))
		end = 1;
	else if (!strcmp(ft_tolower(cmd[0]), "env"))
		while (env[++i])
			printf("%s\n", env[i]);
	else if (!strcmp(ft_tolower(cmd[0]), "pwd"))
		printf("%s\n", getenv("PWD"));
	else
		printf("minishell: error: command \"%s\" not found\n", cmd[0]);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	**line_split;
	int		i;
	
	(void) argc;
	(void) argv;
	end = 0;
	while (!end)
	{
		i = -1;
		line = readline(PROMPT);
		if (line[0])
		{
			add_history(line);
			line_split = ft_split(line, ' ');
			execute(line_split, env);
			while (line_split[++i])
				free(line_split[i]);
			free(line_split);
		}
		free(line);
	}
	system("leaks minishell");
	return (0);
}
