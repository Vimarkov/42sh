/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:15:04 by kdumarai          #+#    #+#             */
/*   Updated: 2018/04/25 09:17:36 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbrcpy_core(char *dst, long nb)
{
	if (nb > 9)
		ft_nbrcpy_core(dst - 1, nb / 10);
	*dst = nb % 10 + '0';
}

void		ft_nbrcpy(char *dst, long nb)
{
	size_t	len;

	if (nb < 0)
	{
		nb = -nb;
		*dst++ = '-';
	}
	len = ft_nbrlen(nb);
	ft_nbrcpy_core(dst + len - 1, nb);
	dst[len] = '\0';
}
