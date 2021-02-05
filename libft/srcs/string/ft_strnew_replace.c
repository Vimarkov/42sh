/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:47:51 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/26 17:41:27 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#ifdef STRREPL_VS

char			*ft_strnew_replace(const char *s,
									const char *find,
									const char *repl)
{
	t_str	vs;
	size_t	find_len;

	if (!ft_tstrnew(&vs))
		return (NULL);
	find_len = ft_strlen(find);
	while (*s)
	{
		if (ft_strstart(s, find))
		{
			if (!ft_tstrcat(&vs, repl))
			{
				ft_tstrdel(&vs);
				return (NULL);
			}
			s += find_len;
			continue ;
		}
		if (!ft_tstrncat(&vs, s++, 1))
		{
			ft_tstrdel(&vs);
			return (NULL);
		}
	}
	return (vs.s);
}

#else

static size_t	get_newlen(const char *s, const char *find, const char *repl)
{
	size_t	ret;
	size_t	relen;

	relen = ft_strlen(repl);
	ret = 0;
	while (*s)
		ret += (ft_strstart(s++, find)) ? relen : 1;
	return (ret);
}

char			*ft_strnew_replace(const char *s,
									const char *find,
									const char *repl)
{
	char			*ret;
	unsigned long	idx;

	if (!(ret = (char*)malloc(sizeof(char) * (get_newlen(s, find, repl) + 1))))
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		if (ft_strstart(s, find))
			(void)ft_strcpy(ret + idx, repl);
		else
			(void)ft_strncpy(ret + idx, s + idx, 1);
		idx++;
	}
	return (ret);
}

#endif
