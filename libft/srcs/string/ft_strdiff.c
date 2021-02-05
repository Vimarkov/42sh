/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:43:19 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/29 02:09:48 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdiff(char *base, const char *check)
{
	if (!base || !check)
		return (NULL);
	while (*base && *check && *base == *check)
	{
		base++;
		check++;
	}
	return (base);
}
