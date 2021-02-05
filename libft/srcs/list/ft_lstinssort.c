/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinssort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 22:42:28 by kdumarai          #+#    #+#             */
/*   Updated: 2018/01/31 18:19:32 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insert_elsewhere(t_list *bw, t_list *curr, \
	int (*f)(t_list *a, t_list *b), int rev)
{
	while (bw)
	{
		if (!bw->next || !(f(curr, bw->next) == !rev))
		{
			curr->next = bw->next;
			bw->next = curr;
			return ;
		}
		bw = bw->next;
	}
}

void		ft_lstinssort(t_list **alst, int (*f)(t_list *a, t_list *b), \
	int rev)
{
	t_list	*ret;
	t_list	*curr;

	if (!*alst || !(*alst)->next)
		return ;
	ret = NULL;
	while (*alst)
	{
		curr = *alst;
		*alst = (*alst)->next;
		if (!ret || !(f(curr, ret) == !rev))
		{
			curr->next = ret;
			ret = curr;
		}
		else
			insert_elsewhere(ret, curr, f, rev);
	}
	*alst = ret;
}
