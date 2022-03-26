/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:10:51 by arudy             #+#    #+#             */
/*   Updated: 2022/03/26 18:29:47 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	manage_redir(t_token **lst, t_token **prev, t_token **head)
{
	t_token	*new;

	new = NULL;
	if ((*lst)->type == REDIR_IN)
	{
		if ((*lst)->next && (*lst)->next->type == REDIR_IN)
			new = copy_tokens(lst, HERE_DOC, *prev, 2);
		else
			new = copy_tokens(lst, REDIR_IN, *prev, 1);
	}
	else
	{
		if ((*lst)->next && (*lst)->next->type == REDIR_OUT)
			new = copy_tokens(lst, DGREATER, *prev, 2);
		else
			new = copy_tokens(lst, REDIR_OUT, *prev, 1);
	}
	token_lst_addback(head, new);
	*prev = new;
}
