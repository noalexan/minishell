/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:17:50 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/17 00:23:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_error_syntax(t_token *t)
{
	ft_putendl_fd("\e[31;1m[minishell]: Error syntax\e[0m", STDERR);
	ft_lstclear(t);
	return (NULL);
}
