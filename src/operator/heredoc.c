/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:38:09 by itaouil 👑        #+#    #+#             */
/*   Updated: 2022/12/08 02:22:23 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clavier_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		exit(0);
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
	char	*line;
	int		p[2];

	pipe(p);
	the_heredoc_donjon();
	echo_control_seq(0);
	signal(SIGINT, clavier_heredoc);
	while (1)
	{
		line = readline("💀🐺 HERE THE DOC 🗡 🛡 > ");
		if (!line || !ft_strcmp(line, limiter))
			break ;
		line = ft_mini_expender(line);
		ft_putendl_fd(line, p[1]);
		free(line);
	}
	close(p[1]);
	return (p[0]);
}
