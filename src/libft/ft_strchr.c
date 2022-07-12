/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:41:35 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;

	i = -1;
	if (!string)
		return (NULL);
	while (string[++i])
		if (((unsigned char *)string)[i] == (unsigned char)searchedChar)
			return (&((char *)string)[i]);
	if (string[i] == searchedChar)
		return (&((char *)string)[i]);
	return (NULL);
}
