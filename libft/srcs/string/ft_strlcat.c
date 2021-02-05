/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:19:28 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 03:15:14 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	p;

	i = ft_strlen(dst);
	p = 0;
	if (size <= i)
		return (i + ft_strlen(src) - (i - size));
	while (src[p] && p + 1 < size - i)
	{
		dst[i + p] = src[p];
		p++;
	}
	dst[i + p] = '\0';
	return (i + ft_strlen(src));
}
