/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:13:29 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/25 01:55:44 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_sethistory(void)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin("/Users/", ft_get_var("USER")->content);
	tmp2 = ft_strjoin(tmp, "/.polnareff_history");
	g_minishell.history_fd = open(tmp2, O_CREAT | O_APPEND | O_RDWR, 00700);
	if (g_minishell.history_fd == -1)
		printf("err %d\n", errno);
	(free(tmp), free(tmp2));
	tmp = get_next_line(g_minishell.history_fd);
	while (tmp)
	{
		tmp[ft_strlen(tmp) - 1] = 0;
		add_history(tmp);
		free(tmp);
		tmp = get_next_line(g_minishell.history_fd);
	}
	if (tmp)
		free(tmp);
}

void	ft_addhistory(const char *str)
{
	printf("Adding \"%s\" to history...\n", str);
	ft_printf(g_minishell.history_fd, "%s\n", str);
	add_history(str);
}
