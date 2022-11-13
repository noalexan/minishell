/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:08:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/08/18 13:04:00 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *source)
{
	char	*copy;

	copy = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, ft_strlen(source));
	return (copy);
}

char	*ft_strdup_and_free(char *source)
{
	char	*copy;

	copy = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, ft_strlen(source));
	free(source);
	return (copy);
}

char	*ft_strldup(const char *source, size_t size)
{
	char	*copy;

	copy = ft_calloc(size + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, size);
	return (copy);
}
