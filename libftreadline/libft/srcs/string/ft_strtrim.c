/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:04:20 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 03:30:28 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				is_whitechar(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

static unsigned long	first_last_index(int first, const char *str)
{
	unsigned long	i;

	i = (first) ? 0 : ft_strlen(str);
	i -= (!first && i > 0);
	while (is_whitechar(str[i]) && (i > 0 || first))
	{
		if (first)
			i++;
		else
			i--;
	}
	return (i);
}

char					*ft_strtrim(char const *s)
{
	char			*ret;
	unsigned long	findex;
	unsigned long	lindex;

	if (!s)
		return (NULL);
	findex = first_last_index(1, s);
	lindex = first_last_index(0, s);
	if (lindex == 0)
		return (ft_strnew(0));
	if (!(ret = ft_strsub(s, (unsigned int)findex, lindex - findex + 1)))
		return (NULL);
	return (ret);
}
