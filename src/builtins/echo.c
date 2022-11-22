/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:14:49 by César             #+#    #+#             */
/*   Updated: 2022/11/22 20:02:46 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	where_is_n(char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	if (s[0] == '-' && s[1] == 'n')
	{
		while (s[i])
		{
			if (s[i] != 'n' && s[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_echo(t_token *token)
{
	t_token	*tmp;
	int		n;

	tmp = token;
	n = 0;
	if (!token)
		return ((void)printf("\n"));
	if (!ft_strcmp(tmp->content, "$?"))
		printf("%d\n", g_exitcode);
	while (where_is_n(tmp->content) && tmp->next && ++n)
		tmp = tmp->next;
	if (where_is_n(tmp->content))
		return ;
	while (tmp)
	{
		printf("%s", tmp->content);
		if (tmp->next)
			printf(" ");
		tmp = tmp->next;
	}
	if (!n)
		printf("\n");
	g_exitcode = 0;
}
