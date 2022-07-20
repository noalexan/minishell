/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:23:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/19 20:57:47 by noahalexand      ###   ########.fr       */
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
	if (*line)
	{
		line_split = ft_split(line, ' ');
		if (*line_split)
		{
			add_history(line);
			*input = ft_lexeur(line);
			while (line_split[++i])
				free(line_split[i]);
		}
		free(line_split);
		free(line);
	}
}

int	ft_minishell(const char *prompt, char **env)
{
	t_input	input;

	(void) env;
	while (1)
	{
		get_input(prompt, &input);
		// printf("\"%s\"\n", input.tokens->content);
		printf("Here\n");
		if (!ft_strcmp(input.tokens->content, "leaks"))
			system("leaks minishell");
		ft_lstclear(input.tokens);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	((void) argc, (void) argv);
	return (ft_minishell(PROMPT, env));
}
