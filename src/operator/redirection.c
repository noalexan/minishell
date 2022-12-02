/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by mayoub            #+#    #+#             */
/*   Updated: 2022/12/02 17:52:27 by mayoub           ###   ########.fr       */
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

void	ft_redirection(void)
{
	t_input	*s;

	s = g_minishell.input;
	while (s)
	{
		ft_parse_redirecion(s->token);
		s = s->next;
	}
}
