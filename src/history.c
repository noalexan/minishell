/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:13:29 by Norminette        #+#    #+#             */
/*   Updated: 2022/12/20 14:24:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_sethistory(void)
{
	char	*tmp;
	t_env	*home;

	home = ft_get_var("HOME");
	if (!home || !home->content || !home->content[0])
		return ;
	if (home)
		tmp = ft_strjoin(home->content, "/.polnareff_history");
	else
		tmp = ft_strdup("/dev/null");
	g_minishell.history_fd = open(tmp, O_CREAT | O_APPEND | O_RDWR, 00700);
	free(tmp);
	if (g_minishell.history_fd == -1)
		printf("err %d\n", errno);
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
	if (g_minishell.history_fd > 2)
		ft_putendl_fd(str, g_minishell.history_fd);
	add_history(str);
}
