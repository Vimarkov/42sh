/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbubblesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:07:34 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 05:50:33 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstswap(t_list **lst, t_list **curr, t_list *prev)
{
	t_list	*tmp;

	if (prev)
		prev->next = (*curr)->next;
	else
		*lst = (*curr)->next;
	tmp = (*curr)->next->next;
	(*curr)->next->next = (*curr);
	(*curr)->next = tmp;
	*curr = *lst;
}

void		ft_lstbubblesort(t_list **lst, int (*cmp)(t_list*, t_list*), \
	int rev)
{
	t_list	*curr;
	t_list	*prev;

	curr = *lst;
	prev = NULL;
	while (curr->next)
	{
		prev = (curr == *lst) ? NULL : prev;
		if (cmp(curr, curr->next) == !rev)
			ft_lstswap(lst, &curr, prev);
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
