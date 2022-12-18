/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:37:50 by Tropico           #+#    #+#             */
/*   Updated: 2022/12/18 13:45:04 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_open_file(t_input *s, t_token *t)
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

void	ft_init_redirection_utils(t_input *s, t_token *t)
{
	if (s->in != STDIN)
		close(s->in);
	if (t->content[1] == '<')
		s->in = ft_heredoc(t->next->content);
	else
	{
		if (!access(t->next->content, 0400))
			s->in = open(t->next->content, O_RDONLY, 0400);
		else
			return ((void) ft_error_no_file(t->next->content));
	}
}
