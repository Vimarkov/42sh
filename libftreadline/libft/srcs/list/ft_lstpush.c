/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:49:57 by kdumarai          #+#    #+#             */
/*   Updated: 2018/02/02 21:53:10 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *add)
{
	t_list	*bw;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = add;
		return ;
	}
	bw = *alst;
	while (bw->next)
		bw = bw->next;
	bw->next = add;
}
