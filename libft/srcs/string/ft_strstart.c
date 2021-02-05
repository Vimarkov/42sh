/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:45:41 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 03:55:14 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strstart(const char *s, const char *check)
{
	if (!s || !check)
		return (NULL);
	while (*check)
	{
		if (*(s++) != *(check++))
			return (NULL);
	}
	return (s);
}
