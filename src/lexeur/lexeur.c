/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:03:28 by mtaouil           #+#    #+#             */
/*   Updated: 2022/07/22 16:04:43 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_skip_space(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

char	*ft_getstr(char *line)
{
	int		i;
	int		quote;
	int		d_quote;
	char	*result;

	i = -1;
	d_quote = FALSE;
	quote = FALSE;
	while (line[++i] && (!ft_isspace(line[i]) || quote || d_quote))
	{
		if (line[i] == '"' && d_quote && !quote)
			d_quote = FALSE;
		else if (line[i] == '"' && !d_quote && !quote)
			d_quote = TRUE;
		else if (line[i] == '\'' && quote && !d_quote)
			quote = FALSE;
		else if (line[i] == '\'' && !quote && !d_quote)
			quote = TRUE;
	}
	if (quote || d_quote)
		printf("Error synthax.\n");
	result = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(result, line, i + 1);
	return (result);
}

void	ft_new_token(t_input *input, char *content)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->content = ft_strdup(content);
	printf("\"%s\"\n", content);
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
	getstr = ft_getstr(line);
	ft_new_token(input, getstr);
	free(getstr);
}

void	ft_lexeur(t_input *input, char *line)
{
	init_tokens(input, line);
}
