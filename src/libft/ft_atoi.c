/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:51:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:23:20 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_isspace(char a)
{
	if ((a == ' ') || (a == '\t') || (a == '\v')
		|| (a == '\n') || (a == '\r') || (a == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	value;
	int		sig;

	value = 0;
	i = 0;
	sig = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		value *= 10;
		value += nptr[i] - 48;
		i++;
	}
	return ((int)value * sig);
}
