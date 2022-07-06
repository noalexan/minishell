/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:17:46 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/06 13:32:52 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_input	parse(char **split)
{
	t_input	input;

	input.cmds = ft_calloc(1, sizeof(t_cmd));
	if (!strcmp(*split, "exit")
		|| !strcmp(*split, "cd")
		|| !strcmp(*split, "env")
		|| !strcmp(*split, "pwd")
		|| !strcmp(*split, "echo")
		|| !strcmp(*split, "unset")
		|| !strcmp(*split, "export"))
		input.cmds->cmd = *split;
	else
		input.cmds->cmd = find_path(*split);
	return (input);
}
