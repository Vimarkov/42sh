/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:39:12 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 02:56:18 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cast;

	cast = (unsigned char*)dst;
	if (src < dst)
	{
		while (len--)
			cast[len] = ((const unsigned char*)src)[len];
	}
	else
		ft_memcpy(cast, src, len);
	return (dst);
}
