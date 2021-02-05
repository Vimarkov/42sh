/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:53:54 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/31 22:13:42 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

inline static t_uint8	in_cset(char c, const char *cset)
{
	while (*cset)
		if (c == *(cset++))
			return (TRUE);
	return (FALSE);
}

static unsigned long	word_cnt(const char *s, const char *cset)
{
	unsigned long	ret;
	unsigned long	notc;
	unsigned long	i;

	ret = 0;
	i = 0;
	notc = 0;
	while (s[++i])
	{
		ret += (in_cset(s[i - 1], cset) && !in_cset(s[i], cset) && i > 1);
		notc += !in_cset(s[i], cset);
	}
	if (!ret && !notc)
		return (0);
	return (ret + 1);
}

static void				*freeretnull(char ***tab)
{
	ft_tabfree(tab);
	return (NULL);
}

char					**ft_strsplit_charset(const char *s, const char *cset)
{
	unsigned int	i;
	unsigned int	p;
	unsigned long	r;
	char			**ret;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * (word_cnt(s, cset) + 1))))
		return (NULL);
	i = 0;
	p = 0;
	r = 0;
	while (s[i] && s[p])
	{
		while (in_cset(s[i], cset))
			i++;
		if (!s[i])
			break ;
		p = (!s[i]) ? i : i + 1;
		while (s[p] && !in_cset(s[p], cset))
			p++;
		if (!(ret[r++] = ft_strsub(s, i, (size_t)(p - i))))
			return (freeretnull(&ret));
		i = p;
	}
	ret[r++] = NULL;
	return (ret);
}
