/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by mayoub            #+#    #+#             */
/*   Updated: 2022/12/03 21:02:26 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    ft_insert_token(t_token *t, t_token *new)
{
    new->next = t->next;
    t->next = new;
}

void	ft_parse_redirecion(t_token *t)
{
	int		s_q;
	int		d_q;
	int		j;

	s_q = FALSE;
	d_q = FALSE;
	j = -1;
	if (t)
	{
		while (t->content[++j] && (s_q || d_q || !ft_isspace(t->content[j])))
		{
			if (t->content[j] == '\'' && !s_q && !d_q)
				s_q = TRUE;
			else if (t->content[j] == '\'' && s_q && !d_q)
				s_q = FALSE;
			else if (t->content[j] == '\"' && !d_q && !s_q)
				d_q = TRUE;
			else if (t->content[j] == '\"' && d_q && !s_q)
				d_q = FALSE;
			if ((t->content[j] == '>' || t->content[j] == '<') && !d_q && !s_q)
				// && !(t->content[j + 1] == '>' || t->content[j + 1] == '<'))
			{
				ft_insert_token(t, ft_lstnew("t-content + j"));
                printf("<<<<<<<<\n");
                // ft_replace_seg(t, "", (int []){j, ft_strlen(t->content) - j, 0});
			}
		}
        ft_parse_redirecion(t->next);
	}
}

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
		// ft_parse_redirecion(s->token);
		ft_pipe_redirection(s);
		printf("\e[1;34m[DEBUG]\e[0m: \e[1;36m[redirection]: in = '%d', out = '%d'\e[0m\n", s->in, s->out);
		ft_redirection(s->next);
	}
}
