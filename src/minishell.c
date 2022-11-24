/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by Krystel           #+#    #+#             */
/*   Updated: 2022/11/23 10:59:15 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_builtins(t_token	*token, t_env *env)
{
	if (!ft_strcmp(token->content, "env"))
		env_exp(token, env, 0);
	else if (!ft_strcmp(token->content, "export"))
		env_exp(token, env, 1);
	else if (!ft_strcmp(token->content, "unset"))
		env_exp(token, env, 2);
	else if (!ft_strcmp(token->content, "echo"))
		ft_echo(token->next);
	else if (!ft_strcmp(token->content, "exitcode"))
		(printf("%d\n", g_exitcode), g_exitcode = 0);
	else
		return (error_unknown(token->content));
	return (1);
}

char	*ft_makeprompt(char *prompt, t_env *env)
{
	t_env	*username;
	char	*tmp;
	char	*tmp2;

	username = ft_get_var("USER", env);
	if (username && username->content)
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

int	ft_minishell(const char *prompt, t_env *env)
{
	t_token	*token;
	char	*line;

	while (1)
	{
		line = readline(prompt);
		if (!line)
			(printf("exit\n"), exit(0));
		token = ft_lexer(&line, env);
		if (token && token->content)
		{
			ft_builtins(token, env);
			// 	ft_execute(token);
			/* =========================================== DEBUG COMMAND ======================================== */
			/**/	if (!ft_strcmp(token->content, "leaks"))													/**/
			/**/		system("leaks minishell");																/**/
			/**/	else if (!strcmp(token->content, "exit"))													/**/
			/**/		(printf("exit\n"), exit(0));																				/**/
			/**/	else if (!ft_strcmp(token->content, "re"))													/**/
			/**/	{																							/**/
			/**/		system("make run");																		/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp(token->content, "del"))													/**/
			/**/	{																							/**/
			/**/		ft_lst_delete(env, "USER");																/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp(token->content, "fre"))													/**/
			/**/	{																							/**/
			/**/		system("make fclean run");																/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp(token->content, "colors"))												/**/
			/**/	{																							/**/
			/**/		int i = 0;																				/**/
			/**/		while (++i <= 9)																		/**/
			/**/		{																						/**/
			/**/			printf(																				/**/
			/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\"  -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
			/**/				(token->next) ? ft_atoi(token->next->content) : 0, i,							/**/
			/**/				(token->next) ? ft_atoi(token->next->content) : 0, i							/**/
			/**/			);																					/**/
			/**/		}																						/**/
			/**/		i = 29;																					/**/
			/**/		while (++i <= 47)																		/**/
			/**/		{																						/**/
			/**/			printf(																				/**/
			/**/				"\e[34;1m[DEBUG]\e[0m: [COLOR]: \"\\e[%d;%dm\" -> \"\e[%d;%dmCOLOR\e[0m\"\n",	/**/
			/**/				(token->next) ? ft_atoi(token->next->content) : 0, i,							/**/
			/**/				(token->next) ? ft_atoi(token->next->content) : 0, i							/**/
			/**/			);																					/**/
			/**/		}																						/**/
			/**/	}																							/**/
			/* ================================================================================================== */
			ft_lstclear(token);
		}
		free(line);
	}
}
