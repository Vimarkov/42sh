/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 04:32:48 by kdumarai          #+#    #+#             */
/*   Updated: 2018/02/22 23:07:57 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrmc(char *s, char c)
{
	char			*ret;
	char			*tmp;
	unsigned int	idx;

	if (!s || !(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	idx = 0;
	tmp = s;
	while (*tmp)
	{
		if (*tmp != c)
			ret[idx++] = *tmp;
		tmp++;
	}
	tmp = ret;
	ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}
