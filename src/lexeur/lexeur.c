/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:03:28 by mtaouil           #+#    #+#             */
/*   Updated: 2022/07/22 12:06:12 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_skip_space(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

char	*ft_getstr(char *line, char chr)
{
	int		i;
	char	*result;

	i = -1;
	while (line[++i] && line[i] != chr)
		;
	result = ft_calloc(i + 1, sizeof(char));
	i = -1;
	while (line[++i] && line[i] != chr)
		result[i] = line[i];
	return (result);
}

void	ft_new_token(t_input *input, char *content)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->content = content;
	token->next = NULL;
	ft_lstadd_back(&input->tokens, token);
}

void	init_tokens(t_input *input, char *line)
{
	char	*getstr;

	line = ft_skip_space(line);
	if (*line == '<' && line++)
	{
		if (*line == '<' && line++)
			ft_new_token(input, "<<");
		else
			ft_new_token(input, "<");
	}
	line = ft_skip_space(line);
	getstr = ft_getstr(line, ' ');
	ft_new_token(input, getstr);
	free(getstr);
}

void	ft_lexeur(t_input *input, char *line)
{
	init_tokens(input, line);
}
