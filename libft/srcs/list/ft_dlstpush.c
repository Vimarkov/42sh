/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:49:57 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/19 12:02:00 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpush(t_dlist **alst, t_dlist *add)
{
	t_dlist	*bw;

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
	add->prev = bw;
}
