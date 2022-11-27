/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:38:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/11/27 23:37:44 by noalexan         ###   ########.fr       */
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
	char	*tmp;
	int		len_of_name;
	t_env	*var;

	len_of_name = ft_sizeof_name(l + i + 1);
	tmp = ft_strldup(l + i + 1, len_of_name);
	var = ft_get_var(tmp);
	printf("ok\n");
	free(tmp);
	if (l[i + 1] == '?' && ft_isforbidden(l[i + 2]))
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: exitcode\e[0m\n");
		tmp = ft_itoa(g_minishell.exitcode);
		ft_replace_segment(l, tmp, i, 2);
		len_of_name = ft_strlen(tmp);
		free(tmp);
		return (5);
	}
	else if (var)
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: name=\"%s\", content=\"%s\"\e[0m\n", var->name, var->content);
		ft_replace_segment(l, var->content, i, len_of_name + 1);
		return (ft_strlen(var->content));
	}
	else
	{
		printf("\e[34;1m[DEBUG]\e[0m: \e[35;1m[variable]: No variable\e[0m\n");
		ft_replace_segment(l, "", i, len_of_name + 1);
		return (0);
	}
}
