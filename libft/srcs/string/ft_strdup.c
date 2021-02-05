/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:24:21 by kdumarai          #+#    #+#             */
/*   Updated: 2018/02/23 14:18:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*ret;
	unsigned int	cnt;

	cnt = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[cnt])
	{
		ret[cnt] = s1[cnt];
		cnt++;
	}
	ret[cnt] = '\0';
	return (ret);
}
