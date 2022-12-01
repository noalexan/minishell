/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   🤖.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/12/01 22:40:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_makeprompt(char *prompt)
{
	t_env	*username;
	char	*tmp;
	char	*tmp2;

	username = ft_get_var("USER");
	if (username && username->content && username->content[0])
	{
		tmp = ft_strjoin("\e[34;1m", username->content);
		tmp2 = ft_strjoin(tmp, "@");
		free(tmp);
		tmp = ft_strjoin(tmp2, prompt);
		free(tmp2);
		return (tmp);
	}
	else
		return (ft_strjoin("\e[34;1mstranger@", prompt));
}

void	ft_clear(t_input *s)
{
	if (s)
	{
		ft_lstclear(s->token);
		ft_clear(s->next);
		free(s);
	}
}

int	ft_minishell(const char *prompt)
{
	char	*line;

	while (1)
	{
		line = readline(prompt);
		if (!line)
			(printf("exit\n"), close(g_minishell.history_fd), exit(0));
		ft_lexer(line);
		ft_clear(g_minishell.input);
	}
}
