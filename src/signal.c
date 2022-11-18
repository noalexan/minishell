/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:27:04 by Mel               #+#    #+#             */
/*   Updated: 2022/11/05 18:40:03 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clavier(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
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
