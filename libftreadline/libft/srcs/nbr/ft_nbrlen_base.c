/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:35:56 by kdumarai          #+#    #+#             */
/*   Updated: 2018/01/05 13:52:14 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen_base(long long nbr, int base)
{
	size_t		ret;

	ret = 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (nbr < base)
		return (1);
	while (nbr >= base)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}
