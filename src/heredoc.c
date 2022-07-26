/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:27:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/26 09:41:56 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_heredoc(char *limiter)
{
	char	*line;
	int		fd[2];

	pipe(fd);
	line = readline("\e[1;34mheredoc > \e[0m");
	while (strcmp(line, limiter))
	{
		ft_printf(fd[1], "%s\n", line);
		free(line);
		line = readline("\e[1;34mheredoc > \e[0m");
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}
