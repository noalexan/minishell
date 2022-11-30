/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:11:11 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/30 22:52:17 by mayoub           ###   ########.fr       */
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

t_token	*ft_get_pipe(t_token *t)
{
	t_token	*new;

	new = t;
	while (t)
	{
		if (!ft_strcmp(t->content, "|"))
			t->next = NULL;
		t = t->next;
	}
	return (new);
}

t_token	**ft_pipe(t_token *t)
{
	t_token	**new;
	int		i;
	int		j;

	i = ft_count_pipe(t) + 1;
	printf("Size: %d\n", i);
	new = ft_calloc(i + 1, sizeof(t_token));
	j = -1;
	while (++j < i)
	{
		new[j] = ft_get_pipe(t);
		t = ft_get_pipe(t);
	}
	return (new);
}
