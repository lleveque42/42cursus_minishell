/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:11 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/06 16:03:16 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_opened	*ft_opened_new(int fd, t_data *data)
{
	t_opened	*new;

	new = ft_malloc(sizeof(t_opened), data);
	new->prev = NULL;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	opened_addback(t_opened *new, t_data *data)
{
	while (data->opened->next)
		data->opened = data->opened->next;
	new->prev = data->opened;
	data->opened->next = new;
	while (data->opened->prev)
		data->opened = data->opened->prev;
}

void	close_all(t_data *data)
{
	t_opened	*tmp;

	while (data->opened)
	{
		tmp = data->opened;
		if (data->opened->fd >= 0)
			close(data->opened->fd);
		data->opened = data->opened->next;
		ft_free(tmp, data);
	}
}

int	ft_open(char *filename, int flags, int mod, t_data *data)
{
	int	fd;

	if (mod)
		fd = open(filename, flags, mod);
	else
		fd = open(filename, flags);
	if (!data->opened)
	{
		data->opened = ft_malloc(sizeof(t_opened), data);
		data->opened->prev = NULL;
		data->opened->fd = fd;
		data->opened->next = NULL;
	}
	else
		opened_addback(ft_opened_new(fd, data), data);
	return (fd);
}
