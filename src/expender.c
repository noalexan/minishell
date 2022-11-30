/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/11/30 20:53:03 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_size_of_name(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] && !((s[i] >= 0 && s[i] <= 64) || s[i] == 91 || s[i] == 93
			|| s[i] == 94 || s[i] == 96 || (s[i] >= 123 && s[i] <= 127)))
		;
	return (i);
}

int	ft_replace_seg(t_token *t, const char *seg, int s, int l, int ret)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strldup(t->content, s);
	tmp2 = ft_strjoin(tmp, seg);
	free(tmp);
	tmp = ft_strdup(t->content + s + l);
	free(t->content);
	t->content = ft_strjoin(tmp2, tmp);
	(free(tmp), free(tmp2));
	return (ret);
}

int	ft_insert_var(t_token *t, int i)
{
	char	*tmp;
	int		len;
	t_env	*var;

	len = ft_size_of_name(t->content + i + 1);
	if (t->content[i + 1] == '?')
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: exitcode = '%d'\e[0m\n", g_minishell.exitcode);
		tmp = ft_itoa(g_minishell.exitcode);
		ft_replace_seg(t, tmp, i, 2, 0);
		free(tmp);
		return (2);
	}
	tmp = ft_substr(t->content, i + 1, len);
	var = ft_get_var(tmp);
	printf("line: %s, i: %d\n", tmp, len);
	free(tmp);
	if (var && var->content && var->content[0])
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: name = \"%s\", content = \"%s\"\e[0m\n", var->name, var->content);
		return (ft_replace_seg(t, var->content, i, len + 1, ft_strlen(var->content)));
	}
	else
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: no variable\e[0m\n");
		return (ft_replace_seg(t, "", i, len + 1, 0));
	}
}

t_token	**ft_expender(t_token **t)
{
	int		s_q;
	int		d_q;
	int		i;
	int		j;

	s_q = FALSE;
	d_q = FALSE;
	j = -1;
	i = -1;
	if (t[++i])
	{
		while (t[i]->content[++j] && (s_q || d_q || !ft_isspace(t[i]->content[j])))
		{
			if (t[i]->content[j] == '\'' && !s_q && !d_q)
				s_q = ft_replace_seg(t[i], "", j--, 1, TRUE);
			else if (t[i]->content[j] == '\'' && s_q && !d_q)
				s_q = ft_replace_seg(t[i], "", j--, 1, FALSE);
			else if (t[i]->content[j] == '\"' && !d_q && !s_q)
				d_q = ft_replace_seg(t[i], "", j--, 1, TRUE);
			else if (t[i]->content[j] == '\"' && d_q && !s_q)
				d_q = ft_replace_seg(t[i], "", j--, 1, FALSE);
			else if (t[i]->content[j] == '$' && !s_q)
				j += ft_insert_var(t[i], j) - 1;
		}
		ft_expender(&(*t)->next);
	}
	return (t);
}
