/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:23:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/11 23:08:51 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_btdelone(t_btree **node, void (*del)(void*, size_t))
{
	if (!node || !*node)
		return ;
	del((*node)->data, (*node)->data_size);
	free(*node);
	*node = NULL;
}
