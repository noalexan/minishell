/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   🤖.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/11/30 19:55:41 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_builtins(t_token	*token)
{
	if (!ft_strcmp(token->content, "env"))
		env_exp(token, 0);
	else if (!ft_strcmp(token->content, "export"))
		env_exp(token, 1);
	else if (!ft_strcmp(token->content, "unset"))
		env_exp(token, 2);
	else if (!ft_strcmp(token->content, "echo"))
		ft_echo(token->next);
	else if (!ft_strcmp(token->content, "cd"))
		ft_cd(token->next);
	else if (!ft_strcmp(token->content, "exit"))
		ft_exit(token);
	else if (!ft_strcmp(token->content, "pwd") && g_minishell.env)
		(printf("%s\n", ft_get_var("PWD")->content), g_minishell.exitcode = 0);
	else
		return (0);
	return (1);
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

int	ft_minishell(const char *prompt)
{
	t_token	**token;
	char	*line;

	while (1)
	{
		line = readline(prompt);
		if (!line)
			(printf("exit\n"), close(g_minishell.history_fd), exit(0));
		token = ft_lexer(line);
		if ((*token) && (*token)->content)
		{
			/* =========================================== DEBUG COMMAND ======================================== */
			/**/	if (!ft_strcmp((*token)->content, "leaks"))													/**/
			/**/		system("leaks minishell");																/**/
			/**/	else if (!ft_strcmp((*token)->content, "re"))												/**/
			/**/	{																							/**/
			/**/		system("make run");																		/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp((*token)->content, "fre"))												/**/
			/**/	{																							/**/
			/**/		system("make fclean run");																/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp((*token)->content, "history-fd"))										/**/
			/**/		printf("history fd: %d\n", g_minishell.history_fd);										/**/
			/**/	else if (!ft_strcmp((*token)->content, "colors"))											/**/
			/**/	{																							/**/
			/**/		int i = 0;																				/**/
			/**/		while (++i <= 9)																		/**/
			/**/		{																						/**/
			/**/			printf(																				/**/
			/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\"  -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
			/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i,						/**/
			/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i						/**/
			/**/			);																					/**/
			/**/		}																						/**/
			/**/		i = 29;																					/**/
			/**/		while (++i <= 47)																		/**/
			/**/		{																						/**/
			/**/			printf(																				/**/
			/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\" -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
			/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i,						/**/
			/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i						/**/
			/**/			);																					/**/
			/**/		}																						/**/
			/**/	}																							/**/
			/**/	else																						/**/
			/* ================================================================================================== */
			if (!ft_builtins(*token))
				if (!ft_execute(*token))
					error_unknown((*token)->content);
			int i = -1;
			while (token[++i])
				ft_lstclear(token[i]);
			free(token);
		}
	}
}
