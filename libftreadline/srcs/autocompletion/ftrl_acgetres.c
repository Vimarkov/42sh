/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_acgetres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:53:53 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 19:02:37 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "ftrl_internal.h"

static const char	*get_last_components(const char *s, const char *comps)
{
	const char	*ret;
	const char	*chk;

	if (!s || !comps)
		return (NULL);
	ret = s;
	while (*s)
	{
		chk = comps;
		while (*chk)
		{
			if (*s == *chk)
				ret = s;
			chk++;
		}
		s++;
	}
	ret += (ret > s);
	return (ret);
}

inline static char	*get_region(char *line, t_cursor *csr)
{
	const char		*tmp;
	const char		*chkcomps = " |;><&=";
	unsigned long	idx;

	if (csr->pos == csr->max)
	{
		if (!(tmp = get_last_components(line, chkcomps)))
			return (NULL);
		return (ft_strdup(tmp + 1));
	}
	idx = csr->pos;
	while (idx--)
	{
		if (ft_strchr(chkcomps, line[idx]))
			break ;
	}
	idx++;
	return (ft_strsub(line, (unsigned int)idx, csr->pos - idx));
}

t_list				*get_ac_result_bltn(char *line, t_cursor *csr)
{
	t_list	*ret;
	char	*region;

	region = get_region(line, csr);
	ret = search_files_begin(region, NULL, FALSE);
	free(region);
	return (ret);
}
