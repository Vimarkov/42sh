/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:23:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/11 19:31:58 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_btdel(t_btree **bt, void (*del)(void*, size_t))
{
	if (!bt || !*bt)
		return ;
	if ((*bt)->left)
		ft_btdel(&(*bt)->left, del);
	if ((*bt)->right)
		ft_btdel(&(*bt)->right, del);
	ft_btdelone(bt, del);
}
