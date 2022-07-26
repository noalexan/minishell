/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:58:10 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/26 09:27:53 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_skip_space(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

int	quote(int value, char *line)
{
	*line = -1;
	return (value);
}
