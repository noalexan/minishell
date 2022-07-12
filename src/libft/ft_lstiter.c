/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:09:55 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:41:25 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstiter(t_stack *lst, void (*f)(t_stack *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
