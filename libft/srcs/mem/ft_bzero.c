/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:19:44 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 02:43:25 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sc;
	size_t			i;

	sc = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		sc[i] = 0;
		i++;
	}
}
