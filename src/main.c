/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/18 19:51:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	g_minishell.env = ft_create_env(envv);
	ft_create_pwd();
	echo_control_seq(0);
	ft_sethistory();
	if (argc > 1)
		parse_arg(argv);
	ft_minishell(ft_makeprompt(PROMPT));
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre

/*

* redirection:
	* expend le name du fichier de output
	? input  : `` echo > $[VARIABLE QUI N'EXISTE PAS] ``
	? output : `` [minishell]: $[VARIABLE QUI N'EXISTE PAS]: ambiguous redirect ``
	? ===> A FIX

* heredoc:
	* mettre plusieurs heredoc dans la meme pipe...

? norme et nettoyage
! C'EST FAIS

*/
