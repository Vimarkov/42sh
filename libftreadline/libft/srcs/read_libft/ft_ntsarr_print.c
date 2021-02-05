/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:32:56 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/12 13:34:24 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

void	ft_ntsarr_print(char **ntsarr, int newline)
{
	int	i;

	i = -1;
	while (ntsarr[++i])
	{
		if (newline)
			ft_putendl(ntsarr[i]);
		else
			ft_putstr(ntsarr[i]);
	}
}
