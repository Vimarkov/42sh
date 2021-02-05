/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:46:01 by kdumarai          #+#    #+#             */
/*   Updated: 2018/01/16 20:06:02 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(long nbr)
{
	size_t	ret;

	ret = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		ret++;
		nbr /= 10;
	}
	return (ret);
}

static void		fill(char *str, long nbr)
{
	if (nbr > 9)
		fill(str - 1, nbr / 10);
	*str = nbr % 10 + '0';
}

char			*ft_lltoa(long long nl)
{
	size_t	len;
	char	*ret;

	len = nbrlen(nl) + (nl < 0);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	if (nl < 0)
	{
		nl = -nl;
		ret[0] = '-';
	}
	fill(ret + len - 1, nl);
	return (ret);
}
