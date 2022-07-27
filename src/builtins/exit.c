/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:11:24 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/27 06:39:10 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_input *input)
{
	if (input->tokens->next)
		exit(ft_atoi(input->tokens->next->content));
	exit(EXIT_SUCCESS);
}
