/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:05:18 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/09 15:17:48 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dlstdelone(t_dlist **alist, void (*del)(void *, size_t))
{
	t_dlist	*nxt;
	t_dlist	*prev;

	if (!alist || !*alist)
		return ;
	nxt = (*alist)->next;
	prev = (*alist)->prev;
	if (del)
		del((*alist)->content, (*alist)->content_size);
	free(*alist);
	if (nxt)
		nxt->prev = prev;
	*alist = nxt;
}
