/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:58:15 by mayoub            #+#    #+#             */
/*   Updated: 2022/11/11 10:16:51 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_token	*ft_lstnew(void *content)
{
	t_token	*new_element;

	new_element = (t_token *)malloc(1 * sizeof(t_token));
	if (new_element == NULL)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
