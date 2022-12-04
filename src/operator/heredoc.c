/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/12/04 20:06:14 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_heredoc(t_token *token)
{
	char	*line;

	(void) token;
	the_heredoc_donjon();
	while (1)
	{
		line = readline("\e[1;30m💀HERE🗡 THE🛡 DOC🧪, take care 🐺> \033[0m");
		(void) line;
	}
}
