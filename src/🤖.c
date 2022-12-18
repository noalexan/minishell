/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   🤖.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/12/18 10:40:21 by mayoub           ###   ########.fr       */
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
		/* =========================================== DEBUG COMMAND ======================================== */
		/**/	if (!ft_strcmp(s->token->content, "leaks"))													/**/
		/**/		system("leaks minishell");																/**/
		/**/	else if (!ft_strcmp(s->token->content, "re"))												/**/
		/**/		(system("make run"), exit(EXIT_SUCCESS));												/**/
		/**/	else if (!ft_strcmp(s->token->content, "fre"))												/**/
		/**/		(system("make fclean run"), exit(EXIT_SUCCESS));										/**/
		/**/	else if (!ft_strcmp(s->token->content, "history-fd"))										/**/
		/**/		printf("history fd: %d\n", g_minishell.history_fd);										/**/
		/**/	else if (!ft_strcmp(s->token->content, "colors"))											/**/
		/**/	{																							/**/
		/**/		int i = 0;																				/**/
		/**/		while (++i <= 9)																		/**/
		/**/		{																						/**/
		/**/			printf(																				/**/
		/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\"  -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
		/**/				(s->token->next) ? ft_atoi(s->token->next->content) : 0, i,						/**/
		/**/				(s->token->next) ? ft_atoi(s->token->next->content) : 0, i						/**/
		/**/			);																					/**/
		/**/		}																						/**/
		/**/		i = 29;																					/**/
		/**/		while (++i <= 47)																		/**/
		/**/		{																						/**/
		/**/			printf(																				/**/
		/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\" -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
		/**/				(s->token->next) ? ft_atoi(s->token->next->content) : 0, i,						/**/
		/**/				(s->token->next) ? ft_atoi(s->token->next->content) : 0, i						/**/
		/**/			);																					/**/
		/**/		}																						/**/
		/**/	}																							/**/
		/**/	else																						/**/
		/* ================================================================================================== */
		if (!ft_builtins(s))
			if (!ft_execute(s))
				error_unknown(s->token->content);
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

void	ft_close_all(t_input *s)
{
	if (s)
	{
		if (s->in != STDIN)
			close(s->in);
		if (s->out != STDOUT)
			close(s->out);
		ft_close_all(s->next);
	}
}

void	ft_wait_all(t_input *s)
{
	if (s)
		(wait(NULL), ft_wait_all(s->next));
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
		free(line);
		ft_exec(g_minishell.input);
		ft_close_all(g_minishell.input);
		ft_wait_all(g_minishell.input);
		ft_clear(g_minishell.input);
	}
}
