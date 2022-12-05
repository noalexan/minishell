/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/05 02:32:54 by noalexan         ###   ########.fr       */
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
	if (argc > 1)
		parse_arg(argv);
	ft_minishell(ft_makeprompt(PROMPT));
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre

/*

a verifier : "env -i ./minishell" puis "export ..=..": segfault

a verifier : """ et "'": segfault

j'ai trop prevu que le gars colle le chevron au reste du texte que j'ai fais des erreurs dans le parsing
(je verrais ca quand j'arrive au cas ou tu lis ca avant)
j'ai aussi essayer 2 3 trucs si tu veux voir c'est dans src/operator/redirection.c

ctrl + c pour kill une commande: double prompt

*/
