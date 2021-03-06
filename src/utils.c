/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:58:10 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/27 09:45:08 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_skip_space(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

char	*ft_skip_word(char *line)
{
	while (!ft_isspace(*line))
		line++;
	return (line);
}

int	quote(int value, char *line)
{
	*line = -1;
	return (value);
}
