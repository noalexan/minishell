/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:55 by tle               #+#    #+#             */
/*   Updated: 2022/12/01 22:51:58 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_new_token(t_token **token, char *content)
{
	t_token	*new;

	if (content && content[0])
	{
		new = ft_calloc(1, sizeof(t_token));
		new->content = ft_strdup(content);
		new->next = NULL;
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
		g_minishell.exitcode = 258;
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

void	*ft_lexer(char *line)
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
	if (g_minishell.exitcode == 258)
	{
		ft_putendl_fd("\e[31;1m[minishell]: Error syntax\e[0m", 2);
		ft_lstclear(token);
		g_minishell.exitcode = 127;
		return (NULL);
	}
	if (line)
		free(line);
	ft_pipe(token);
	ft_expender();
	return (NULL);
}
