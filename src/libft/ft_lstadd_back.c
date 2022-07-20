/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:54:11 by noahalexand       #+#    #+#             */
/*   Updated: 2022/07/19 15:38:42 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*last;

	if (*lst != NULL)
	{
		last = *lst;
		last = ft_lstlast(*lst);
		last->next = new;
		return ;
	}
	*lst = new;
}
