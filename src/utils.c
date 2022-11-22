/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:59:11 by sspina          #+#    #+#             */
/*   Updated: 2022/11/16 18:01:49 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_skip_space(char *line, int i)
{
	int	j;

	j = -1;
	while (ft_isspace(line[++j + i]))
		;
	return (j);
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

t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_env	*ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!lst)
		return (NULL);
	else if (*lst)
	{
		last = ft_lstlast_env(*lst);
		last->next = new;
	}
	else
		*lst = new;
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
	t_env	*tmp;

	tmp = env;
	while (env->next != unset)
		env = env->next;
	free(unset->content);
	free(unset->name);
	free(unset);
	env->next = unset->next;
	env = tmp;
}

void	ft_free(void *a)
{
	if (a)
		free(a);
}
