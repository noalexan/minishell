/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:42:24 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *)destination;
	b = (char *)source;
	while (i < size)
	{
		a[i] = b[i];
		i++;
	}
	return (destination);
}
