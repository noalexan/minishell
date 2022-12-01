/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:11:11 by Rondoudou         #+#    #+#             */
/*   Updated: 2022/12/01 22:14:57 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_get_pipe(t_token *t)
{
	t_token	*a;

	a = NULL;
	if (t && t->content && ft_strcmp(t->content, "|"))
	{
		a = ft_calloc(1, sizeof(t_token));
		a->content = ft_strdup(t->content);
		a->next = NULL;
		a->next = ft_get_pipe(t->next);
	}
	return (a);
}

t_token	*ft_get_token(t_token *t)
{
	if (t && t->content && t->content[0])
	{
		if (ft_strcmp(t->content, "|"))
			return (ft_get_token(t->next));
		else
			return (t->next);
	}
	return (NULL);
}

t_input	*ft_create_input(t_token *t)
{
	t_input	*a;

	a = NULL;
	if (t)
	{
		a = ft_calloc(1, sizeof(t_input));
		a->in = 0;
		a->out = 1;
		a->token = ft_get_pipe(t);
		a->next = ft_create_input(ft_get_token(t));
	}
	return (a);
}

void	ft_pipe(t_token *t)
{
	g_minishell.input = ft_create_input(t);
	ft_lstclear(t);
}
