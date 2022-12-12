/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by Keyblade          #+#    #+#             */
/*   Updated: 2022/12/11 20:54:57 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_parse_redirecion(t_token *t, int s_q, int d_q, int j)
{
	int	i;

	if (t)
	{
		while (t->content[++j])
		{
			if (t->content[j] == '\'' && !d_q)
				s_q = 1 - s_q;
			else if (t->content[j] == '\"' && !s_q)
				d_q = 1 - d_q;
			if (!d_q && !s_q && (t->content[j] == '>' || t->content[j] == '<'))
			{
				i = 1;
				if (j)
					i = j;
				if (!j && t->content[j + 1] == t->content[j])
					i++;
				if (t->content[i + 1])
					(ft_insert_token(t, ft_lstnew(t->content + i)),
						ft_replace_seg(t, "",
							(int []){i, ft_strlen(t->content) - i, 0}));
			}
		}
		ft_parse_redirecion(t->next, FALSE, FALSE, -1);
	}
}

void	ft_init_redirection(t_input *s, t_token *t)
{
	if (t)
	{
		if (t->content[0] == '>' || t->content[0] == '<')
			if (!t->next)
				return (error_synthax_export(0));
		if (t->content[0] == '>')
		{
			if (s->out != STDOUT)
				close(s->out);
			if (t->content[1] == '>')
				s->out = open(t->next->content,
						O_CREAT | O_WRONLY | O_APPEND, 0600);
			else
				s->out = open(t->next->content,
						O_CREAT | O_WRONLY | O_TRUNC, 0600);
		}
		else if (t->content[0] == '<')
		{
			if (s->in != STDIN)
				close(s->in);
			if (t->content[1] == '<')
				s->in = ft_heredoc(t->next->content);
			else
				s->in = open(t->next->content, O_RDONLY, 0400);
		}
		else
			return ((void) ft_init_redirection(s, t->next));
		ft_init_redirection(s, t->next->next);
	}
}

void	ft_pipe_redirection(t_input *s)
{
	int	pipe_fd[2];

	if (s->next)
	{
		pipe(pipe_fd);
		if (s->out == STDOUT)
			s->out = pipe_fd[IN];
		else
			close(pipe_fd[IN]);
		if (s->next->in == STDIN)
			s->next->in = pipe_fd[OUT];
		else
			close(pipe_fd[OUT]);
	}
}

t_token	*ft_clear_tokens(t_token *t)
{
	t_token	*tmp;

	if (t && t->next)
	{
		if (t->content[0] == '<' || t->content[0] == '>')
		{
			tmp = t;
			t = t->next->next;
			tmp->next->next = NULL;
			printf("removing... '%s'\n", tmp->content);
			printf("removing... '%s'\n", tmp->next->content);
			ft_lstclear(tmp);
		}
		else if (t->next->content[0] == '<' || t->next->content[0] == '>')
		{
			tmp = t->next;
			t->next = t->next->next->next;
			tmp->next->next = NULL;
			printf("removing... '%s'\n", tmp->content);
			printf("removing... '%s'\n", tmp->next->content);
			ft_lstclear(tmp);
		}
		t->next = ft_clear_tokens(t->next);
	}
	return (t);
}

void	ft_redirection(t_input *s)
{
	if (s)
	{
		ft_parse_redirecion(s->token, FALSE, FALSE, -1);
		ft_init_redirection(s, s->token);
		s->token = ft_clear_tokens(s->token);
		ft_pipe_redirection(s);
		if (s->in < 0 || s->out < 0)
			return ((void) ft_putendl_fd("Error", STDERR), ft_clear(g_minishell.input));
		printf("\e[1;34m[DEBUG]\e[0m: \e[1;36m[redirection]: in = '%d', out = '%d'\e[0m\n", s->in, s->out);
		ft_redirection(s->next);
	}
}
