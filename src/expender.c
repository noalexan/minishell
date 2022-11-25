/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/11/25 02:01:22 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_change_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			str[i] = -5;
	return (str);
}

int	ft_isforbidden(char s)
{
	if ((s >= 0 && s <= 64) || s == 91 || s == 93 || s == 94 || s == 96
		|| (s >= 123 && s <= 127))
		return (1);
	return (0);
}

int	ft_size_of_name(char *str)
{
	int	i;

	i = -1;
	while (!ft_isforbidden(str[++i]))
		;
	return (i);
}

char	*ft_expender(char **l, int i)
{
	char	*line;
	char	*tmp;
	int		j;
	t_env	*variable;

	j = ft_size_of_name((*l) + i + 1);
	tmp = ft_strldup((*l) + i + 1, j);
	variable = ft_get_var(tmp);
	free(tmp);
	if (variable && variable->content)
	{
		line = ft_strldup((*l), i);
		tmp = ft_strjoin(line, variable->content);
		free(line);
		line = ft_strjoin(tmp, (*l) + i + j + 1);
		printf("\e[34;1m[DEBUG]: \e[35;1m[variable]: name = \"%s\", conte\
nt = \"%s\"\n\e[0m", variable->name, variable->content);
		free(tmp);
		free(*l);
		return (line);
	}
	else
	{
		printf("tmp = '%s'\n", tmp);
		free(*l);
		return (ft_strdup("dsfsdghsdfdsfdfdgsdgsdfgsdgdfgdfgfdgdfgdrggdr"));
	}
}
