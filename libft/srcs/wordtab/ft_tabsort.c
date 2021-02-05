/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:31:01 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/13 15:55:49 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabsort(char **tab)
{
	int		i;
	char	*bak;

	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
		{
			bak = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = bak;
			i = 0;
		}
		i++;
	}
}
