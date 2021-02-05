/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:15:04 by kdumarai          #+#    #+#             */
/*   Updated: 2018/04/25 09:18:11 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbrcat_core(char *dst, long nb)
{
	if (nb > 9)
		ft_nbrcat_core(dst - 1, nb / 10);
	*dst = nb % 10 + '0';
}

void		ft_nbrcat(char *dst, long nb)
{
	size_t	len;

	while (*dst)
		dst++;
	if (nb < 0)
	{
		nb = -nb;
		*dst++ = '-';
	}
	len = ft_nbrlen(nb);
	ft_nbrcat_core(dst + len - 1, nb);
	dst[len] = '\0';
}
