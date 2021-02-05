/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putubt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:45:10 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/10 01:41:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putubt_core(t_btree *bt,
							void (*ft_putelem)(void*, size_t),
							int lvl)
{
	ft_putnbr(lvl);
	ft_putstr(": ");
	ft_putelem(bt->data, bt->data_size);
	if (bt->left)
	{
		ft_putnbr(lvl);
		ft_putstr(": ");
		ft_putendl("turn left");
		ft_putubt_core(bt->left, ft_putelem, lvl + 1);
		ft_putnbr(lvl + 1);
		ft_putstr(": ");
		ft_putendl("back up");
	}
	if (bt->right)
	{
		ft_putnbr(lvl);
		ft_putstr(": ");
		ft_putendl("turn right");
		ft_putubt_core(bt->right, ft_putelem, lvl + 1);
		ft_putnbr(lvl + 1);
		ft_putstr(": ");
		ft_putendl("back up");
	}
}

void		ft_putubt(t_btree *bt, void (*ft_putelem)(void*, size_t))
{
	if (!bt || !ft_putelem)
		return ;
	ft_putubt_core(bt, ft_putelem, 0);
}
