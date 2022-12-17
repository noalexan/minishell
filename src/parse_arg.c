/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:36:27 by Johanna 🌷        #+#    #+#             */
/*   Updated: 2022/12/16 23:04:19 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_arg(char **argv)
{
	int		fd;
	char	*line;

	if (access(argv[1], F_OK) != 0)
		return (error_not_a_directory(argv[1], 0), exit(1));
	else if (opendir(argv[1]))
		return (error_not_a_directory(argv[1], 2), exit(1));
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			(close(fd), exit(0));
		ft_lexer(line);
		free(line);
		ft_exec(g_minishell.input);
		ft_close_all(g_minishell.input);
		ft_wait_all(g_minishell.input);
		ft_clear(g_minishell.input);
	}
}
