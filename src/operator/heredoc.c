/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/20 08:15:34 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clavier_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		(printf("\n"), exit(5));
}

char	*ft_mini_expender(char *s)
{
	int		s_q;
	int		d_q;
	int		j;
	t_token	*t;

	t = ft_lstnew(s);
	s_q = FALSE;
	d_q = FALSE;
	j = -1;
	while (t->content[++j] && (s_q || d_q || !ft_isspace(t->content[j])))
	{
		if (t->content[j] == '\'' && !d_q)
			s_q = 1 - s_q;
		else if (t->content[j] == '\"' && !s_q)
			d_q = 1 - d_q;
		else if (t->content[j] == '$' && !s_q)
			j += ft_insert_var(t, j) - 1;
	}
	free(s);
	s = ft_strdup(t->content);
	ft_lstclear(t);
	return (s);
}

int	ft_heredoc(char *limiter)
{
	char		*line;
	int			p[2];
	int			tmp;

	(pipe(p), tmp = fork(), g_minishell.heredoc = 0);
	if (tmp == 0)
	{
		(the_heredoc_donjon(), signal(SIGINT, clavier_heredoc), close(p[OUT]));
		while (1)
		{
			line = readline("💀🐺 \e[1;30mHERE THE DOC 🗡 🛡\e[0m > ");
			if (!line || !ft_strcmp(line, limiter))
				break ;
			line = ft_mini_expender(line);
			(ft_putendl_fd(line, p[IN]), free(line));
		}
		(close(p[IN]), exit(0));
	}
	waitpid(tmp, &tmp, 0);
	if (tmp / 256 == 5)
		return (ft_clear(g_minishell.input), g_minishell.input = NULL,
			close(p[IN]), close(p[OUT]), g_minishell.exitcode = 1, -2);
	close(p[IN]);
	return (p[OUT]);
}
