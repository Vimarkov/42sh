/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 07:11:00 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/28 23:20:54 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftrl_internal.h"

void	ftrl_histadd(t_dlist **headref, char *line)
{
	t_dlist	*new;

	if (!headref || !line || !(new = ft_dlstnew(line, ft_strlen(line) + 1)))
		return ;
	if (!*headref)
		*headref = ft_dlstnew(NULL, 0);
	if ((*headref)->next)
	{
		(*headref)->next->prev = new;
		new->next = (*headref)->next;
	}
	new->prev = *headref;
	(*headref)->next = new;
}

void	ftrl_histdelf(void *data, size_t size)
{
	(void)size;
	free(data);
}

void	ftrl_histdellast(t_dlist **headref)
{
	t_dlist	**tmp;

	tmp = headref;
	while ((*tmp)->next)
		tmp = &(*tmp)->next;
	ft_dlstdelone(tmp, &ftrl_histdelf);
}
