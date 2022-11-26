/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/11/26 22:52:10 by noalexan         ###   ########.fr       */
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

int	ft_sizeof_name(char *l)
{
	int	i;

	i = 0;
	while (l[i] && !ft_isforbidden(l[i]))
		i++;
	return (i);
}

int	ft_expender(char *l, int i)
{
	char	*name;
	int		len_of_name;
	t_env	*var;

	len_of_name = ft_sizeof_name(l + i + 1);
	name = ft_strldup(l + i + 1, len_of_name);
	printf("name: %s, len: %d\n", name, len_of_name);
	var = ft_get_var(name);
	free(name);
	if (var)
	{
		printf("var content: %s\n", var->content);
		ft_replace_segment(l, var->content, i, len_of_name + 1);
		return (ft_strlen(var->content));
	}
	else
	{
		printf("no var\n");
		printf("i: %d\n", i);
		printf("line: %s\n", l);
		ft_replace_segment(l, "", i, len_of_name + 1);
		printf("line: %s\n", l);
		return (0);
	}
	return (0);
}
