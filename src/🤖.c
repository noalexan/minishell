/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   🤖.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/12/20 14:19:05 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_builtins(t_input	*s)
{
	if (!ft_strcmp(s->token->content, "echo"))
		ft_exec_echo(s);
	else if (!ft_strcmp(s->token->content, "pwd") && g_minishell.env)
		ft_exec_pwd(s);
	else if (!ft_strcmp(s->token->content, "env"))
		env_exp(s, 0);
	else if (!ft_strcmp(s->token->content, "export"))
		env_exp(s, 1);
	else if (!ft_strcmp(s->token->content, "unset"))
		env_exp(s, 2);
	else if (!ft_strcmp(s->token->content, "cd"))
		ft_cd(s->token->next);
	else if (!ft_strcmp(s->token->content, "exit"))
		ft_exit(s->token);
	else
		return (0);
	return (1);
}

void	ft_exec(t_input *s)
{
	if (s)
	{
		if (s->token)
			if (!ft_builtins(s))
				ft_execute(s);
		ft_exec(s->next);
	}
}

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
		ft_clear(s->next);
		ft_lstclear(s->token);
		free(s);
	}
	g_minishell.input = NULL;
}

int	ft_minishell(const char *prompt)
{
	char	*line;

	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, clavier_int);
		line = readline(prompt);
		if (!line)
			(printf("exit\n"), close(g_minishell.history_fd), exit(0));
		ft_lexer(line);
		free(line);
		ft_exec(g_minishell.input);
		ft_close_all(g_minishell.input);
		ft_wait_all(g_minishell.input);
		ft_clear(g_minishell.input);
	}
}
