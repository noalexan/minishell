/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by Tac               #+#    #+#             */
/*   Updated: 2022/07/22 15:56:00 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_input(const char *prompt, t_input *input)
{
	char	*line;
	char	**line_split;
	int		i;

	i = -1;
	line = readline(prompt);
	input->tokens = NULL;
	if (*line)
	{
		line_split = ft_split(line, ' ');
		if (*line_split)
		{
			add_history(line);
			ft_lexeur(input, line);
			while (line_split[++i])
				free(line_split[i]);
		}
		free(line_split);
	}
	free(line);
}

int	ft_minishell(const char *prompt, char **env)
{
	t_input	input;

	(void) env;
	g_end = FALSE;
	while (!g_end)
	{
		get_input(prompt, &input);
		if (input.tokens)
		{
			if (!ft_strcmp(input.tokens->content, "leaks"))
				system("leaks minishell");
			ft_lstclear(input.tokens);
		}
	}
	return (g_end);
}

int	main(int argc, char **argv, char **env)
{
	((void) argc, (void) argv);
	return (ft_minishell(PROMPT, env));
}
