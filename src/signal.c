/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:27:04 by Mel               #+#    #+#             */
/*   Updated: 2022/12/19 11:31:50 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clavier_quit(int sig_num)
{
	if (sig_num == SIGQUIT)
		(printf("\e[1;31m[Bruhhhh wtf] \e[0m\e[1;30m^\\Quit: 3 💀\e[0m\n"),
			g_minishell.exitcode = 131);
}

void	clavier_int2(int sig_num)
{
	if (sig_num == SIGINT)
		(printf("\e[1;31m[Bruhhhh wtf] \e[0m\e[1;30m^C 🥴\e[0m\n"),
			g_minishell.exitcode = 130);
}

void	clavier_int(int sig_num)
{
	if (g_minishell.input)
		g_minishell.exitcode = 130;
	else
	{
		if (sig_num == SIGINT)
		{
			printf("\n");
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_minishell.exitcode = 1;
		}
	}
}

void	echo_control_seq(int c)
{
	struct termios	conf;

	ioctl(ttyslot(), TIOCGETA, &conf);
	if (c == 1)
		conf.c_lflag |= ECHOCTL;
	else if (c == 0)
		conf.c_lflag &= ~(ECHOCTL);
	ioctl(ttyslot(), TIOCSETA, &conf);
}
