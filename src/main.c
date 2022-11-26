/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/11/25 04:52:37 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	((void) argc, (void) argv, (void) envv);
	g_minishell.env = ft_create_env(envv);
	echo_control_seq(0);
	signal(SIGINT, clavier);
	ft_sethistory();
	ft_minishell(ft_makeprompt(PROMPT));
	system("leaks minishell");
	return (0);
}

// Version : 0.1.0
// Authors : Marwan Ayoub, Noah Alexandre

// ! S'OCCUPER DU EXIT_CODE
// ! S'OCCUPER DU '$?'
// ! "env -i ./minishell" : segfault
