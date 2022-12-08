/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/12/08 01:32:14 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clavier_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		exit(0);
}

char	*ft_mini_expender(char *line, int s)
{
	int	i;

	i = s - 1;
	while (line[++i])
	{
		if (line[i] == '$')
			printf("variable\n");
	}
	return (line);
}

int	ft_heredoc(char *limiter)
{
	char	*line;
	int		p[2];

	pipe(p);
	the_heredoc_donjon();
	echo_control_seq(0);
	signal(SIGINT, clavier_heredoc);
	line = readline("💀🐺 HERE THE DOC 🗡 🛡 > ");
	while (1)
	{
		if (!line || !ft_strcmp(line, limiter))
			break ;
		line = ft_mini_expender(line, 0);
		ft_putendl_fd(line, p[1]);
		free(line);
		line = readline("💀🐺 HERE THE DOC 🗡 🛡 > ");
	}
	free(line);
	close(p[1]);
	return (p[0]);
}
