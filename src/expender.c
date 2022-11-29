/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/11/29 20:02:37 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isforbidden(char s)
{
	if ((s >= 0 && s <= 64) || s == 91 || s == 93 || s == 94 || s == 96
		|| (s >= 123 && s <= 127))
		return (1);
	return (0);
}

int	ft_size_of_name(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] && !ft_isforbidden(str[i]))
		;
	return (i);
}

int	ft_expender(char *l, int i)
{
	char	*tmp;
	int		len;
	t_env	*var;

	if (!l || !l[i])
		return (0);
	if (l[i + 1] == '?' && ft_isforbidden(l[i + 2]))
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: exitcode = '%d'\e[0m\n", g_minishell.exitcode);
		return (0);
	}
	len = ft_size_of_name(l + i + 1);
	tmp = ft_substr(l, i + 1, len);
	printf("name: %s, len: %d\n", tmp, len);
	var = ft_get_var(tmp);
	free(tmp);
	if (var && var->content && var->content[0])
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: name=\"%s\", content=\"%s\"\e[0m\n", var->name, var->content);
	}
	else
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: no variable\e[0m\n");
		tmp = ft_strldup(l, i);
		char *tmp2 = ft_strdup(l + i + len + 1);
		printf("tmp = \"%s\", tmp2 = \"%s\"\n", tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	l = ft_strdup("echo salut");
	return (0);
}
