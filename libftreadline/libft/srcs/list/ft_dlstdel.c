/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:51 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/23 19:32:42 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;
	t_dlist	*bak;

	if (!alst)
		return ;
	tmp = *alst;
	while (tmp)
	{
		bak = tmp->next;
		ft_dlstdelone(&tmp, del);
		tmp = bak;
	}
	*alst = NULL;
}
