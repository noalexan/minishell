/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:37 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/22 16:42:22 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!source || !destination)
		return (0);
	printf("%s\n", source);
	if (size > 0)
		while (source[++i] && i < size - 1)
			if (source[i] != -1)
				destination[j++] = source[i];
	destination[j++] = '\0';
	printf("destination: %s\n", destination);
	return (ft_strlen(source));
}
