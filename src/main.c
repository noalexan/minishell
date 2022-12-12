/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/12 09:26:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	g_minishell.env = ft_create_env(envv);
	ft_create_pwd();
	echo_control_seq(0);
	signal(SIGINT, clavier);
	ft_sethistory();
	if (argc > 1)
		parse_arg(argv);
	ft_minishell(ft_makeprompt(PROMPT));
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre

/*
	TODO : mettre touts les bugs/problèmes a fix ci-dessous ===> '✅' si résolut

* pipe:
	* '.. || ..': segfault lorsque plusieurs pipes sont collees

* redirection:
	* '[redirection] ..': segfault lorsqu'il y a juste une redirection
	* '.. >>>>> ..': segfault lorsqu'il y a plus de 4 chevrons

* heredoc:
	* double heredoc sur la meme commande: segfault

? norme et nettoyage

*/
