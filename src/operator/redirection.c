/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by mayoub            #+#    #+#             */
/*   Updated: 2022/12/04 20:27:52 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_put_token(t_token *t, t_token *new)
{
	new->next = t->next;
	t->next = new;
}

void	ft_parse_redirecion(t_token *t, int s_q, int d_q, int j)
{
	int		j2;

	if (t)
	{
		while (t->content[++j] && (s_q || d_q || !ft_isspace(t->content[j])))
		{
			if (t->content[j] == '\'' && !d_q)
				s_q = 1 - s_q;
			else if (t->content[j] == '\"' && !d_q && !s_q)
				d_q = 1 - d_q;
			if ((t->content[j] == '>' || t->content[j] == '<') && !d_q && !s_q)
			{
				j2 = 1;
				if (j)
					j2 = j;
				(ft_put_token(t, ft_lstnew(t->content + j2)), ft_replace_seg(
						t, "", (int []){j2, ft_strlen(t->content) - j2, 0}));
			}
		}
		ft_parse_redirecion(t->next, FALSE, FALSE, -1);
	}
}

// 0644

void	ft_pipe_redirection(t_input *s)
{
	int	pipe_fd[2];

	if (s->next)
	{
		pipe(pipe_fd);
		s->out = pipe_fd[1];
		s->next->in = pipe_fd[0];
	}
}

void	ft_redirection(t_input *s)
{
	if (s)
	{
		ft_parse_redirecion(s->token, FALSE, FALSE, -1);
		ft_pipe_redirection(s);
		printf("\e[1;34m[DEBUG]\e[0m: \e[1;36m[redirection]: in = '%d', out = '%d'\e[0m\n", s->in, s->out);
		ft_redirection(s->next);
	}
}
