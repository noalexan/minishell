/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/17 09:09:24 by noalexan         ###   ########.fr       */
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

* main:
	* je pense qu'il faudra enlever le 'parse_arg()' parce que c'est
		cool pour le debut mais c'est pas cense etre comme ca donc vu que
		c'est pas demandé je pense c'est mieux

exitcode:
	* erreur syntax qui persiste je pense il faut bien faire en sorte que les commande le remette a zero ou le change en cas de probleme

* redirection:
	* expend le name du fichier de output

* heredoc:
	* mettre plusieurs heredoc dans la meme pipe...

? norme et nettoyage

*/
