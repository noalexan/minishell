/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:50:42 by UwU               #+#    #+#             */
/*   Updated: 2022/11/18 21:27:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_export(char *str)
{
	printf("\e[31;1m[minishell]: export: `%s': not a valid identifier\n\e[0m",
		str);
}
