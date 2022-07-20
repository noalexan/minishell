/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:03:28 by noahalexand       #+#    #+#             */
/*   Updated: 2022/07/19 20:54:55 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

	lexeur.tokens = init_tokens(line);
	return (lexeur);
}
