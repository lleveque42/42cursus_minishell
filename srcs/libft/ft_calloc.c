/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:19:08 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:24:46 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_calloc(size_t nmemb, size_t size, t_data *data)
{
	void	*dst;

	dst = ft_malloc(nmemb * size, data);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
