/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/14 14:55:45 by noalexan         ###   ########.fr       */
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

char	*ft_variable(char **l, int i, t_env *env)
{
	char	*line;
	char	*tmp;
	int		j;
	t_env	*variable;

	j = ft_size_of_name((*l) + i + 1);
	tmp = ft_strldup((*l) + i + 1, j);
	variable = ft_get_var(tmp, env);
	free(tmp);
	if (variable && variable->content)
	{
		line = ft_strldup((*l), i);
		tmp = ft_strjoin(line, variable->content);
		free(line);
		line = ft_strjoin(tmp, (*l) + i + ++j);
		printf("i=%d, j=%d, tmp=%s, name=%s, content=%s, line=%s, after=%s, result=%s\n", i, j, tmp, variable->name, variable->content, (*l), (*l) + i + j + 1, line);
		free(tmp);
		free(*l);
		return (line);
	}
	else
		return ("");
}
