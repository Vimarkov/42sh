/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:44:56 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/28 17:45:04 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrf(const char *s, char c)
{
	unsigned long	last;
	unsigned long	idx;

	idx = 0;
	last = 0;
	while (s[idx])
	{
		if (s[idx] == c && idx == last + 1)
			return (TRUE);
		if (s[idx] == c)
			last = idx;
		idx++;
	}
	return (FALSE);
}
