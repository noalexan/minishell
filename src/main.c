/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by flemaitr          #+#    #+#             */
/*   Updated: 2022/11/29 20:15:45 by mayoub           ###   ########.fr       */
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

/*

"env -i ./minishell" puis "export ..=..": segfault ✅
""" et "'": segfault ✅
expender: not work
ft_replace_segment: bancal sa mere
voir si on peut retirer des fonction dans src/utils.c
(et pas les deplacés hein mais vrm les supprimer)

!! FAUT QU'ON ENLEVE FT_PRINTF
dans les fonctions autorisée y a pas va_start, etc mais y a write et printf
pour ecrire dans un fichier faudra faire ft_putstr_fd()
ou alors on peut faire un dossier ft_printf pour garder les fonction mais jsp

*/
