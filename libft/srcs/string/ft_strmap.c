/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:50:21 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/08 16:44:42 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	i = -1;
	if (!s || !(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		ret[i] = f(s[i]);
	return (ret);
}
