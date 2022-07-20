/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:03:28 by mtaouil           #+#    #+#             */
/*   Updated: 2022/07/20 16:54:37 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_input	redirect(t_input *tokens, char *line)
{
	t_input	redirect;

	redirect.in = 0;
	redirect.out = 1;
	if (*line == '>' || *line == '<')
		redirect.tokens = tokens->tokens;
	return (redirect);
}

t_token	*init_tokens(char *line)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->content = line;
	token->next = NULL;
	return (token);
}

t_input	ft_lexeur(char *line)
{
	t_input	lexeur;

	while (ft_isspace(*line))
		line++;
	lexeur.tokens = init_tokens(line);
	printf("%c\n", *line);
	lexeur = redirect(&lexeur, line);
	return (lexeur);
}
