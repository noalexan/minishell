/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:03:28 by mtaouil           #+#    #+#             */
/*   Updated: 2022/07/27 15:59:29 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getstr(char *line)
{
	int		i;
	int		s_quote;
	int		d_quote;
	char	*result;

	i = -1;
	d_quote = FALSE;
	s_quote = FALSE;
	line = ft_skip_space(line);
	while (line[++i] && (!ft_isspace(line[i]) || s_quote || d_quote))
	{
		if (line[i] == '"' && d_quote && !s_quote)
			d_quote = quote(FALSE, &(line[i]));
		else if (line[i] == '"' && !d_quote && !s_quote)
			d_quote = quote(TRUE, &(line[i]));
		else if (line[i] == '\'' && s_quote && !d_quote)
			s_quote = quote(FALSE, &(line[i]));
		else if (line[i] == '\'' && !s_quote && !d_quote)
			s_quote = quote(TRUE, &(line[i]));
	}
	if (s_quote || d_quote)
		return (NULL);
	result = ft_calloc(i + 1, sizeof(char));
	if (*line)
	{
		ft_strlcpy(result, line, i + 1);
		*line += i;
	}
	return (result);
}

void	ft_new_token(t_input *input, char *content)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->content = ft_strdup(content);
	token->next = NULL;
	printf("[lexer]: New token: \"%s\"\n", token->content);
	ft_lstadd_back(&input->tokens, token);
}

void	init_tokens(t_input *input, char *line)
{
	char	*getstr;

	line = ft_redirection(input, line);
	getstr = ft_getstr(line);
	while (getstr)
	{
		printf("\"%s\"\n", line);
		getstr = ft_getstr(line);
		if (g_out)
			printf("minishell: \e[0;33mError synthax\e[0m");
		else if (getstr)
			ft_new_token(input, getstr);
		free(getstr);
	}
	free(getstr);
}

void	ft_lexer(t_input *input, char *line)
{
	init_tokens(input, line);
	if (!strcmp(input->tokens->content, "exit"))
		ft_exit(input);
}
