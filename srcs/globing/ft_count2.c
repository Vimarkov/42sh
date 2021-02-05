/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 05:29:22 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 04:01:42 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

char			*fuck_stars_norm(char **past, char **ret)
{
	char		*final;
	int			j;

	j = 0;
	while ((*ret)[j])
	{
		if (ft_strnequ(*ret + j, *past, ft_strlen(*past)))
		{
			final = ft_strndup(*ret, j);
			ft_strdel(past);
			ft_strdel(ret);
			return (final);
		}
		j++;
	}
	ft_strdel(past);
	ft_strdel(ret);
	return (NULL);
}

void			fuck_stars_norm2(char **test, char **prev, char **ret)
{
	int			j;

	j = 0;
	while ((*test)[j])
	{
		if (!*prev)
			break ;
		if (ft_strnequ((*test) + j, *prev, ft_strlen(*prev)))
		{
			*ret = ft_strdup((*test) + j + ft_strlen(*prev));
			break ;
		}
		j++;
	}
}

int				ft_globing_star(char *test, char *name, char **known, t_glob x)
{
	(void)test;
	x.n = x.u;
	while (name[x.n])
	{
		if (ft_strnequ(name + x.n, known[x.o], ft_strlen(known[x.o])))
			return (x.n - x.u + ft_strlen(known[x.o]));
		else
			x.n++;
	}
	return (-1);
}
