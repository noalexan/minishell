/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:14:49 by César             #+#    #+#             */
/*   Updated: 2022/12/02 16:33:27 by mayoub           ###   ########.fr       */
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
	g_minishell.exitcode = 0;
}

void	ft_exec_echo(t_input *s)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(0, s->in);
		dup2(1, s->out);
		ft_echo(s->token->next);
		exit(0);
	}
}
