/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:55 by tle               #+#    #+#             */
/*   Updated: 2022/12/20 14:22:28 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_new_token(t_token **token, char *content)
{
	t_token		*new;
	static int	j;

	j = 0;
	if (content && content[0])
	{
		new = ft_calloc(1, sizeof(t_token));
		new->content = ft_strdup(content);
		new->next = NULL;
		if (j == 0 && !ft_strcmp(new->content, "|"))
		{
			g_minishell.pipe = 1;
			j = 1;
		}
		else if (j == 0 && !ft_strcmp(new->content, ">"))
		{
			g_minishell.pipe = 2;
			j = 1;
		}
		ft_lstadd_back(token, new);
	}
}

char	*ft_getstr(char *l, int i)
{
	int		s_q;
	int		d_q;
	int		j;

	s_q = FALSE;
	d_q = FALSE;
	j = -1;
	while (l[++j + i] && (s_q || d_q || !ft_isspace(l[j + i])))
	{
		if (l[i + j] == '\'' && !s_q && !d_q)
			s_q = TRUE;
		else if (l[i + j] == '\'' && s_q && !d_q)
			s_q = FALSE;
		else if (l[i + j] == '"' && !d_q && !s_q)
			d_q = TRUE;
		else if (l[i + j] == '"' && d_q && !s_q)
			d_q = FALSE;
		if (l[i + j + 1] == '|' && !d_q && !s_q)
			return (ft_strldup(l + i, j + 1));
		else if (l[i + j] == '|' && !d_q && !s_q)
			return (ft_strdup("|"));
	}
	if (s_q || d_q)
		g_minishell.exitcode = 300;
	return (ft_strldup(l + i, j));
}

t_token	*ft_generate_token(char *line, int i)
{
	t_token		*token;
	char		*str;

	token = NULL;
	if (line && line[i])
	{
		i += ft_skip_space(line + i);
		if (line[i])
		{
			str = ft_getstr(line, i);
			ft_new_token(&token, str);
			token->next = ft_generate_token(line, i + ft_strlen(str));
			free(str);
		}
	}
	return (token);
}

void	ft_lexer(char *line)
{
	t_token	*token;
	int		i;

	token = NULL;
	i = 0;
	if (line && line[i])
	{
		ft_addhistory(line);
		i += ft_skip_space(line);
		if (line[i])
			token = ft_generate_token(line, i);
	}
	if (g_minishell.exitcode == 300)
		return ((void) ft_error_syntax(token));
	ft_pipe(token);
	ft_redirection(g_minishell.input);
	ft_expender();
	ft_verify();
	ft_lstclear(token);
}
