/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:27:01 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/08 16:34:07 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;
	size_t			i;

	if (!(ret = (unsigned char*)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return ((void*)ret);
}
