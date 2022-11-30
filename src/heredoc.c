/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/11/30 23:18:01 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_heredoc(t_token *token)
{
	(void) token;
	while (1)
	{
		// the_heredoc_donjon();
		readline((const char *)"🌈 \e[1;30mH\e[1;31me\e[1;32mR\e[1;33me\e[1;37mD\e[1;34mo\e[1;35mC \e[1;36m🌈 >\e[0m");
	}
}
