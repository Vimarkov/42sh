/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:29:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/01 01:45:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_secatoi(int *dest, const char *str)
{
	if (!dest)
		return (-1);
	if (ft_strlen(str) >= 10
		&& ((*str == '-' && ft_strcmp(str, "-2147483648") < 0)
			|| ft_strcmp(str, "2147483647") > 0))
		return (0);
	*dest = ft_atoi(str);
	return (1);
}
