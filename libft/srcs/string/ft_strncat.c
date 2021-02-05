/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:27:01 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (s1[i])
		i++;
	while (s2[p] && p < n)
	{
		s1[i] = s2[p];
		i++;
		p++;
	}
	s1[i] = '\0';
	return (s1);
}
