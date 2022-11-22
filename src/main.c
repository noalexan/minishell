/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/11/22 20:03:58 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_env	*env;

	((void) argc, (void) argv, (void) envv);
	env = ft_create_env(envv);
	echo_control_seq(0);
	signal(SIGINT, clavier);
	ft_minishell(ft_makeprompt(PROMPT, env), env);
	system("leaks minishell");
	return (0);
}

// Version : 1.0.0
// Author : Marwan Ayoub, Noah Alexandre

// ! S'OCCUPER DU EXIT_CODE
// ! S'OCCUPER DU '$?'
