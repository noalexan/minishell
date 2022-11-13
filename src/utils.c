/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:59:11 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/13 19:03:34 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_skip_space(char *line, int i)
{
	int	j;

	j = -1;
	while (ft_isspace(line[++j + i]))
		;
	return (j);
}
