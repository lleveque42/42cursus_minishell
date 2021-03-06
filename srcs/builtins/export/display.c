/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:15:36 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/05 16:15:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_export(char **dup, t_data *data)
{
	int		i;
	char	**dupdup;

	i = -1;
	while (dup[++i])
	{
		dupdup = ft_nsplit(dup[i], '=', 2, data);
		printf("declare -x %s=\"%s\"\n", dupdup[0], dupdup[1]);
		free_strs(dupdup, data);
	}
}

void	sort_export(t_data *data)
{
	char	**dup;
	char	*tmp;
	int		i;
	int		j;

	dup = dup_env(data->env, data);
	i = -1;
	while (dup[++i])
	{
		j = i;
		while (dup[++j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
		}
	}
	print_export(dup, data);
	free_strs(dup, data);
}
