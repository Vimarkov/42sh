/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:21:30 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 18:21:59 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnnext(t_list *alst, size_t len)
{
	if (!alst)
		return (NULL);
	while (alst && len--)
		alst = alst->next;
	return (alst);
}
