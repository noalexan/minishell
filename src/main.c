/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by tac               #+#    #+#             */
/*   Updated: 2022/07/26 17:29:20 by mayoub           ###   ########.fr       */
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

void	ft_minishell(const char *prompt, char **env)
{
	t_input	input;

	(void) env;
	while (1)
	{
		get_input(prompt, &input);
		if (input.tokens)
		{
			if (!ft_strcmp(input.tokens->content, "leaks"))
				system("leaks minishell");
			if (!ft_strcmp(input.tokens->content, "heredoc"))
			{
				int	fd = ft_heredoc("end");
				char *r = ft_calloc(100, sizeof(char));
				read(fd, r, 100);
				printf("%s", r);
			}
			ft_lstclear(input.tokens);
		}
	}
	system("leaks minishell");
}

int	main(int argc, char **argv, char **env)
{
	((void) argc, (void) argv);
	ft_minishell(PROMPT, env);
	return (0);
}
