/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:11:54 by gscalisi          #+#    #+#             */
/*   Updated: 2022/12/19 16:52:09 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exec_pwd(t_input *s)
{
	if (fork() == 0)
	{
		dup2(s->in, 0);
		dup2(s->out, 1);
		ft_close_all(g_minishell.input);
		printf("%s\n", ft_get_var("PWD")->content);
		exit(0);
	}
	g_minishell.exitcode = 0;
}
