/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:37 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:40:06 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;

	i = -1;
	if (!source || !destination)
		return (0);
	if (size > 0)
		while (source[++i] && i < size - 1)
			destination[i] = source[i];
	destination[i] = '\0';
	return (ft_strlen(source));
}
