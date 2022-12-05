/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/12/05 18:39:17 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clavier_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		exit(0);
}

void	ft_heredoc(t_token *token)
{
	char	*line;

	(void) token;
	the_heredoc_donjon();
	echo_control_seq(0);
	signal(SIGINT, clavier_heredoc);
	while (1)
	{
		line = readline("💀🐺 HERE THE DOC 🗡 🛡 > ");
		if (!line)
			break ;
	}
}
