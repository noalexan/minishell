/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:29 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/14 10:23:14 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
			// if (!ft_builtin(token, env, lenv, lexp))
			// 	ft_execute(token);
			/* =========================================== DEBUG COMMAND ======================================== */
			/**/	if (!ft_strcmp(token->content, "leaks"))													/**/
			/**/		system("leaks minishell");																/**/
			/**/	else if (!strcmp(token->content, "exit"))													/**/
			/**/		exit(0);																				/**/
			/**/	else if (!ft_strcmp(token->content, "re"))													/**/
			/**/	{																							/**/
			/**/		system("make run");																		/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp(token->content, "fre"))													/**/
			/**/	{																							/**/
			/**/		system("make fclean run");																/**/
			/**/		exit(EXIT_SUCCESS);																		/**/
			/**/	}																							/**/
			/**/	else if (!ft_strcmp(token->content, "-env"))												/**/
			/**/	{																							/**/
			/**/		t_env *tmp = env;																		/**/
			/**/		while (tmp)																				/**/
			/**/		{																						/**/
			/**/			printf("%s=%s\n", tmp->name, tmp->content);											/**/
			/**/			tmp = tmp->next;																	/**/
			/**/		}																						/**/
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
