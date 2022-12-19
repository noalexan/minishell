/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/12/19 16:51:31 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_size_of_name(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] && !((s[i] >= 0 && s[i] <= 64) || s[i] == 91 || s[i] == 93
			|| s[i] == 94 || s[i] == 96 || (s[i] >= 123 && s[i] <= 127)))
		;
	return (i);
}

int	ft_replace_seg(t_token *t, const char *seg, int *s)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strldup(t->content, s[0]);
	tmp2 = ft_strjoin(tmp, seg);
	free(tmp);
	tmp = ft_strdup(t->content + s[0] + s[1]);
	if (t->content)
		free(t->content);
	t->content = ft_strjoin(tmp2, tmp);
	(free(tmp), free(tmp2));
	return (s[2]);
}

int	ft_insert_var(t_token *t, int i)
{
	char	*tmp;
	int		len;
	t_env	*var;

	len = ft_size_of_name(t->content + i + 1);
	if (t->content[i + 1] == '?')
	{
		tmp = ft_itoa(g_minishell.exitcode);
		ft_replace_seg(t, tmp, (int []){i, 2, 0});
		free(tmp);
		return (2);
	}
	tmp = ft_substr(t->content, i + 1, len);
	var = ft_get_var(tmp);
	free(tmp);
	if (var && var->content && var->content[0])
		return (ft_replace_seg(t, var->content,
				(int []){i, len + 1, ft_strlen(var->content)}));
	else
		return (ft_replace_seg(t, "", (int []){i, len + 1, 0}));
}

t_token	*ft_expend_token_list(t_token *t)
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
				s_q = ft_replace_seg(t, "", (int []){j--, 1, TRUE});
			else if (t->content[j] == '\'' && s_q && !d_q)
				s_q = ft_replace_seg(t, "", (int []){j--, 1, FALSE});
			else if (t->content[j] == '\"' && !d_q && !s_q)
				d_q = ft_replace_seg(t, "", (int []){j--, 1, TRUE});
			else if (t->content[j] == '\"' && d_q && !s_q)
				d_q = ft_replace_seg(t, "", (int []){j--, 1, FALSE});
			else if (t->content[j] == '$' && t->content[j + 1] && !s_q)
				j += ft_insert_var(t, j) - 1;
		}
		ft_expend_token_list(t->next);
	}
	return (t);
}

void	ft_expender(void)
{
	t_input	*s;

	s = g_minishell.input;
	while (s)
	{
		ft_expend_token_list(s->token);
		s = s->next;
	}
}
