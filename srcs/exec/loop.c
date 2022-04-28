/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:08:27 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/27 20:27:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

int	loop(t_data *data, char **envp)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		prompt = get_prompt(data, envp);
		line = readline(prompt);
		if (!line)
			break ;
		ft_free(prompt, data);
		if (*line)
		{
			add_history(line);
			if (parsing(line, data) == 0)
			{
				if (data->nb_cmd == 1 && check_builtins(data->cmd_lst))
					g_exit_status = exec_builtins(data->cmd_lst, data);
				else
					start_exec(data->cmd_lst, data);
				free_lst(data);
			}
		}
	}
	printf("exit\n");
	return (g_exit_status);
}