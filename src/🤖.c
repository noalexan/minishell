/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   🤖.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/12/01 21:40:42 by mayoub           ###   ########.fr       */
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
	char	*line;

	while (1)
	{
		line = readline(prompt);
		if (!line)
			(printf("exit\n"), close(g_minishell.history_fd), exit(0));
		ft_lexer(line);

		int i = 0;
		printf("{\n");
		while (g_minishell.input && ++i)
		{
			printf("\t\"tab[%d]\":[\n", i);
			while (g_minishell.input->token)
			{
				printf("\t\t\"%s\",\n", g_minishell.input->token->content);
				g_minishell.input->token = g_minishell.input->token->next;
			}
			printf("\t],\n");
			g_minishell.input = g_minishell.input->next;
		}
		printf("}\n");

		// if (token && (*token) && (*token)->content)
		// {
		// 	/* =========================================== DEBUG COMMAND ======================================== */
		// 	/**/	if (!ft_strcmp((*token)->content, "leaks"))													/**/
		// 	/**/		system("leaks minishell");																/**/
		// 	/**/	else if (!ft_strcmp(token->content, "pwd") && g_minishell.env)								/**/
		// 	/**/		(printf("%s\n", ft_get_var("PWD")->content), g_minishell.exitcode = 0);					/**/
		// 	/**/	else if (!ft_strcmp(token->content, "heredoc"))												/**/
		// 	/**/		ft_heredoc(token);																		/**/
		// 	/**/	else if (!ft_strcmp((*token)->content, "re"))												/**/
		// 	/**/	{																							/**/
		// 	/**/		system("make run");																		/**/
		// 	/**/		exit(EXIT_SUCCESS);																		/**/
		// 	/**/	}																							/**/
		// 	/**/	else if (!ft_strcmp((*token)->content, "fre"))												/**/
		// 	/**/	{																							/**/
		// 	/**/		system("make fclean run");																/**/
		// 	/**/		exit(EXIT_SUCCESS);																		/**/
		// 	/**/	}																							/**/
		// 	/**/	else if (!ft_strcmp((*token)->content, "history-fd"))										/**/
		// 	/**/		printf("history fd: %d\n", g_minishell.history_fd);										/**/
		// 	/**/	else if (!ft_strcmp((*token)->content, "colors"))											/**/
		// 	/**/	{																							/**/
		// 	/**/		int i = 0;																				/**/
		// 	/**/		while (++i <= 9)																		/**/
		// 	/**/		{																						/**/
		// 	/**/			printf(																				/**/
		// 	/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\"  -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
		// 	/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i,						/**/
		// 	/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i						/**/
		// 	/**/			);																					/**/
		// 	/**/		}																						/**/
		// 	/**/		i = 29;																					/**/
		// 	/**/		while (++i <= 47)																		/**/
		// 	/**/		{																						/**/
		// 	/**/			printf(																				/**/
		// 	/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\" -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
		// 	/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i,						/**/
		// 	/**/				((*token)->next) ? ft_atoi((*token)->next->content) : 0, i						/**/
		// 	/**/			);																					/**/
		// 	/**/		}																						/**/
		// 	/**/	}																							/**/
		// 	/**/	else																						/**/
		// 	/* ================================================================================================== */
		// 	if (!ft_builtins())
		// 		if (!ft_execute())
		// 			error_unknown((*token)->content);
		// }
	}
}
