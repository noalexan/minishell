/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:08:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:23:36 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *source)
{
	char	*copy;

	copy = ft_calloc(ft_strlen(source) + 5, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, ft_strlen(source));
	return (copy);
}
