/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btattach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:23:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/05 16:25:13 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btattach(t_btree *node, t_btree *left, t_btree *right)
{
	if (!node)
		return ;
	node->left = left;
	node->right = right;
}
