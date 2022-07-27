/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:33:38 by noahalexand       #+#    #+#             */
/*   Updated: 2022/07/27 09:44:16 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_redirection(t_input *input, char *line)
{
	char	*getstr;

	line = ft_skip_space(line);
	if (*line == '<' && line++)
	{
		if (*line == '<' && line++)
		{
			getstr = ft_getstr(line);
			input->in = ft_heredoc(getstr);
			free(getstr);
		}
		else
			printf("File\n");
	}
	return (line);
}
