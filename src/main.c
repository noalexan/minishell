/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/11 18:37:18 by noalexan         ###   ########.fr       */
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

* lorsque + de une redirection : 'execve' prend le reste en arg ce qui casse tout
* '[CMD] || [CMD]' : segf			! ===> plusieurs pipes collées
* '[CMD] >>>>> [CMD] : segf			! ===> au moins 5 chevrons collés
* double heredoc : fix ou revoir le systeme de fork du heredoc + error cat
* '[minishell]: <<: command not found' quand la commande commence par '<<' puis sortis du HD

? norme et nettoyage

*/
