/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:47:18 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/06 17:56:39 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_cmd_lst(t_cmd **lst, t_data *data)
{
	t_cmd	*tmp;
	int		i;

	while (*lst)
	{
		i = 0;
		tmp = *lst;
		while (tmp->cmd[i] != NULL)
		{
			ft_free(tmp->cmd[i], data);
			i++;
		}
		ft_free(tmp->cmd, data);
		if (tmp->cmd_name)
			ft_free(tmp->cmd_name, data);
		if (tmp->bin_path)
			ft_free(tmp->bin_path, data);
		*lst = (*lst)->next;
		ft_free(tmp, data);
	}
}

void	ft_free_garbage(t_garbage *garbage)
{
	t_garbage	*tmp;

	while (garbage && garbage->next)
	{
		tmp = garbage;
		if (garbage && garbage->ptr)
			free(garbage->ptr);
		garbage = garbage->next;
		free(tmp);
	}
	if (garbage)
	{
		free(garbage->ptr);
		free(garbage);
	}
}

void	free_env(t_env *lst, t_data *data)
{
	t_env	*tmp;
	int		i;

	if (!lst)
		return ;
	while (lst)
	{
		i = 0;
		tmp = lst;
		while (lst->var[i])
		{
			ft_free(lst->var[i], data);
			i++;
		}
		ft_free(lst->var, data);
		lst = lst->next;
		ft_free(tmp, data);
	}
}
