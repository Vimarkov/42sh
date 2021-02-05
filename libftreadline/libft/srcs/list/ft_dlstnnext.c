/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnnext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:21:30 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 18:26:21 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstnnext(t_dlist *alst, long len)
{
	if (!alst)
		return (NULL);
	while (alst && len != 0)
	{
		if (len > 0)
		{
			alst = alst->next;
			len--;
		}
		else if (len < 0)
		{
			alst = alst->prev;
			len++;
		}
	}
	return (alst);
}
