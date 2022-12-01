/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/12/01 17:41:22 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_heredoc(t_token *token)
{
	(void) token;
	char	*line;

	the_heredoc_donjon();
	while (1)
	{
		line = readline("🌈 \e[1;30mH\e[1;31me\e[1;32mR\e[1;33me\e[1;37mD\e[1;34mo\e[1;35mC \e[1;36m🌈 > \e[0m");
	}
}
