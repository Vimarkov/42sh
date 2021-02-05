/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 08:10:34 by kdumarai          #+#    #+#             */
/*   Updated: 2018/04/29 22:14:01 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisnumeric(char *s)
{
	if (!*s)
		return (FALSE);
	while (*s)
	{
		if (!ft_isdigit(*(s++)))
			return (FALSE);
	}
	return (TRUE);
}
