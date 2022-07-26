/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by tac               #+#    #+#             */
/*   Updated: 2022/07/26 10:55:56 by noalexan         ###   ########.fr       */
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
			ft_lexer(input, line);
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
			if (!ft_strcmp(input.tokens->content, "heredoc"))
			{
				int	fd = ft_heredoc(input.tokens->next->content);
				char *r = ft_calloc(100, sizeof(char));
				read(fd, r, 100);
				printf("%s", r);
			}
			ft_lstclear(input.tokens);
		}
	}
	system("leaks minishell");
	return (g_end);
}

int	main(int argc, char **argv, char **env)
{
	((void) argc, (void) argv);
	return (ft_minishell(PROMPT, env));
}
