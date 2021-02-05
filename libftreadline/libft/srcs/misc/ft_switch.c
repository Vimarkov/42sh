/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 08:15:12 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 23:28:45 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_switch(const void *dataref,
				const void *tableref,
				size_t tablelen,
				int (*cmp)(const void *, const void *))
{
	void	*dt;
	void	*adr;

	while (*(void**)((t_uintptr)tableref + tablelen - sizeof(void*) * 2))
	{
		if (cmp(dataref, tableref))
		{
			dt = *(void**)((t_uintptr)tableref + tablelen - sizeof(void*));
			adr = *(void**)((t_uintptr)tableref + tablelen - sizeof(void*) * 2);
			return (((int (*)(void *))adr)(dt));
		}
		tableref = (void*)((t_uintptr)tableref + tablelen);
	}
	return (FALSE);
}
