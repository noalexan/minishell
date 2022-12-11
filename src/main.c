/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/12/11 10:13:12 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
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
	TODO : mettre touts les bugs/problèmes a fix ci-dessous ===> '✅' si résolut


! L.41 && L.42 in 🤖.c [DEBUG_WINDOW] : segf quand 'unset PWD' suivi d'une autre commande
//! L.79 - /src/builtins/export.c : j'ai du raccourcir au max la ft error pour la norm mdr c'est degueu mais pas le choix pour corriger le double error de unset
* ||---> j'ai recorrigé tout ça et rajouté 'parse_unset_name' dans 'unset.c'

* revoir le parsing du contenu dans export ✅
* 'unset PATH' suivi de 'pwd' : segf ✅
* 'unset [UNDEFINED_NAME]' : segf ✅
* 'unset PWD' suivi de 'cd [path]' : segf ✅
* 'cd [UNDEFINED_FILE]' : leaks ✅
* 'OLDPWD' dans l'env : pas màj ✅
* 'env [ARGUMENT]' : n'affiche pas d'erreur ✅
* unset [INVALID_IDENTIFIER] : affiche 2 fois l'erreur avec 'export' ✅
* lorsque + de une redirection : 'execve' prend le reste en arg ce qui casse tout
? PAS FIXABLE //// 'cd [FILE]' : marche pas en 'env -i ./minishell'
* 'echo $ a' : ne print pas le '$'
* '[CMD] || [CMD]' : segf			! ===> plusieurs pipes collées
* '[CMD] >>>>> [CMD] : segf			! ===> au moins 5 chevrons collés
* 'pwd' : segf (revoir peut-etre comment le refaire) ? Il passait dans l'execve et c'est de la !TRICHE!
* double heredoc : fix ou revoir le systeme de fork du heredoc + error cat
* '[minishell]: <<: command not found' quand la commande commence par '<<' puis sortis du HD

? norme et nettoyage

*/
