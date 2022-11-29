/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:55 by tle               #+#    #+#             */
/*   Updated: 2022/11/29 19:57:32 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef struct s_getstr
{
	char	*line;
	int		size;
}		t_getstr;

void	ft_new_token(t_token **token, char *content)
{
	t_token	*new;

	if (content && content[0])
	{
		new = ft_calloc(1, sizeof(t_token));
		new->content = ft_strdup(content);
		new->next = NULL;
		printf("\e[34;1m[DEBUG]\e[0m: \e[1;32m[lexer]: New token: \"%s\"\e[0m\n",
			content);
		ft_lstadd_back(token, new);
	}
}

int	ft_quote(int value, char *quote)
{
	*quote = *quote;
	return (value);
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
			s_q = ft_quote(TRUE, &l[i + j]);
		else if (l[i + j] == '\'' && s_q && !d_q)
			s_q = ft_quote(FALSE, &l[i + j]);
		else if (l[i + j] == '"' && !d_q && !s_q)
			d_q = ft_quote(TRUE, &l[i + j]);
		else if (l[i + j] == '"' && d_q && !s_q)
			d_q = ft_quote(FALSE, &l[i + j]);
		else if (l[i + j] == '$' && !s_q)
			j += ft_expender(l, i + j);
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

t_token	*ft_lexer(char *line)
{
	t_token	*token;
	int		i;

	token = NULL;
	i = 0;
	if (line && line[i])
	{
		ft_addhistory(line);
		printf("\e[34;1m[DEBUG]\e[0m: line\t  -> \"%s\"\n", line);
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
		free(line); // ! DOUBLE FREE() ICI + DANS EXPENDER L.57
	return (token);
}
