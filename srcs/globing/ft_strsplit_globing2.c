/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_globing2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:54:54 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 03:59:19 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

void			nb_words_norm(char *str, int *i, int *ret)
{
	if (str[*i] == '*' || str[*i] == '?' || str[*i] == '[')
	{
		if (str[*i] == '[')
			while (str[*i] && str[*i] != ']')
				(*i)++;
		if (str[*i])
			(*i)++;
		else if (str[*i] == '?' || str[*i] == '*')
			while (str[*i] && (str[*i] == '?' || str[*i] == '*'))
				(*i)++;
		if (str[*i] && str[*i] != '*' && str[*i] != '?' && str[*i] != '[')
			(*ret)++;
	}
	else
		(*i)++;
}

char			*norm_surface_improving(char *path, char *test, char *surface)
{
	char *tmp;
	char *tmp2;

	tmp = NULL;
	if (path)
	{
		tmp = ft_souder(path, test, "/");
		tmp2 = ft_strjoin(tmp, surface + ft_length(path, surface));
	}
	else
		tmp2 = ft_strjoin(test, surface + ft_length(path, surface));
	ft_strdel(&tmp);
	return (tmp2);
}
