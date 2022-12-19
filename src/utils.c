/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:59:11 by sspina            #+#    #+#             */
/*   Updated: 2022/12/19 16:48:38 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_skip_space(char *line)
{
	int	i;

	i = -1;
	while (ft_isspace(line[++i]))
		;
	return (i);
}

int	is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

t_env	*ft_lstadd_back_env(t_env *new)
{
	t_env	*tmp;

	if (!g_minishell.env)
	{
		g_minishell.env = new;
		return (new);
	}
	tmp = g_minishell.env;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_env	*ft_lstnew_env(void *content)
{
	t_env	*new_element;

	new_element = (t_env *)malloc(1 * sizeof(t_env));
	if (new_element == NULL)
		return (NULL);
	if (!is_equal(content))
		new_element->content = NULL;
	else
		new_element->content = ft_get_content(content);
	new_element->name = ft_get_name(content);
	new_element->next = NULL;
	return (new_element);
}

void	ft_lst_delone_env(t_env *env, t_env *unset)
{
	if (env && unset)
	{
		if (env == unset)
		{
			g_minishell.env = unset->next;
			free(unset->content);
			free(unset->name);
			free(unset);
		}
		if (env->next == unset)
		{
			env->next = unset->next;
			free(unset->content);
			free(unset->name);
			free(unset);
		}
		else
			ft_lst_delone_env(env->next, unset);
	}
}
