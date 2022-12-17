/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/17 17:36:55 by mayoub           ###   ########.fr       */
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
	! UPDATE : c'est réglé : j'ai utilisé une valeur temporaire pour l'exitcode

* /error/error.c
	* n'affiche pas la bonne erreur pour "No such file or directory"
	! UPDATE : réglé

* redirection:
	* expend le name du fichier de output
	? input  : `` echo > $[VARIABLE QUI N'EXISTE PAS]
	? output : `` [minishell]: $[VARIABLE QUI N'EXISTE PAS]: ambiguous redirect ``
	? ===> A FIX

* heredoc:
	* mettre plusieurs heredoc dans la meme pipe...

* OLDPWD:
	* une foi minishell lancé, la commande ' env '  ===>  ' OLDPWD="" '  au lieu de --->  ' OLDPWD '
	* avant de changer de repertory
	! UPDATE : c'est réglé : à regarder dans le fichier '/src/env.c'

* expend:
	* le lexeur bug un peu lorsque le code d'erreur est égal à 0
	* exemple : `` echo "$USER$USER""$USER'$USER$USER$?""'$USER"  ``
	* output  : `` mayoubmayoubmayoub'mayoubmayoub0"$USER" ``
	* bash    : `` mayoubmayoubmayoub'mayoubmayoub0'mayoub ``
	* si le code d'erreur aurait était différant de 0, ça marche

? norme et nettoyage

*/
