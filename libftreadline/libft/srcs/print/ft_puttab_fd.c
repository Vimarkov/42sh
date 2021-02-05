/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:29:18 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 03:08:04 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, char *tabname, int outfd)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		if (tabname)
		{
			ft_putstr_fd(tabname, outfd);
			ft_putstr_fd("[", outfd);
			ft_putnbr_fd(i, outfd);
			ft_putstr_fd("]: ", outfd);
		}
		ft_putendl_fd(tab[i], outfd);
		i++;
	}
}
