/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:24:21 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/21 17:57:02 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(ret, s1, len);
	return (ret);
}
