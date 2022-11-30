/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:11:11 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/30 20:47:28 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_count_pipe(t_token *t)
{
	if (t)
	{
		if (!ft_strcmp(t->content, "|"))
			return (1 + ft_count_pipe(t->next));
		else
			return (0 + ft_count_pipe(t->next));
	}
	return (0);
}

t_token	**ft_pipe(t_token *t)
{
	t_token **new;
	int		i;

	i = ft_count_pipe(t);
	printf("Size: %d\n", i);
	new = ft_calloc(2, sizeof(t_token));
	new[0] = t;
	return (new);
}
