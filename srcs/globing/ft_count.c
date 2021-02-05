/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 05:29:22 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 04:01:42 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

static int		ft_pass_it(char *surface, int i)
{
	if (surface[i] == ']')
	{
		i--;
		while (surface[i] != '[' && i > 0)
			i--;
		if (surface[i] == '[' && i > 0)
			i--;
	}
	else
		i--;
	return (i);
}

char			*ft_get_the_prev(int i, char *surface)
{
	int		ret;
	char	*prev;

	prev = NULL;
	ret = 0;
	i--;
	if (i < 0)
		return (0);
	while (i > 0 && (surface[i] == ']' || surface[i] == '?' ||
				surface[i] == '*') && surface[i] != '/')
		i = ft_pass_it(surface, i);
	while (i > 0 && surface[i] != ']' && surface[i] != '?' &&
			surface[i] != '*' && surface[i] != '/')
		i--;
	if (i > 0)
		i++;
	while (surface[i] && surface[i] != '[' && surface[i] != '?'
			&& surface[i] != '*' && surface[i] != '/')
	{
		ret++;
		i++;
	}
	if (ret)
		return (prev = ft_strndup(surface + i - ret, ret));
	return (NULL);
}

char			*ft_get_the_past(int i, char *surface)
{
	int		ret;
	char	*past;

	past = NULL;
	ret = 0;
	while (surface[i] && (surface[i] == '[' || surface[i] == '?' ||
				surface[i] == '*') && surface[i] != '/')
		i = ft_pass_theses(i, surface);
	while (surface[i] && surface[i] != '[' && surface[i] != '?' &&
			surface[i] != '*' && surface[i] != '/')
	{
		i++;
		ret++;
	}
	if (!surface[i - ret])
		return (NULL);
	if (ret)
		past = ft_strndup(surface + i - ret, ret);
	return (past);
}

char			*fuck_stars(char *test, int i, char *surface)
{
	char	*prev;
	char	*past;
	char	*ret;
	char	*final;

	ret = NULL;
	final = NULL;
	prev = ft_get_the_prev(i, surface);
	past = ft_get_the_past(ft_pass_theses(i, surface), surface);
	fuck_stars_norm2(&test, &prev, &ret);
	ft_strdel(&prev);
	if (!ret)
		ret = ft_strdup(test);
	if (!past)
		return (ret);
	if ((final = fuck_stars_norm(&past, &ret)))
		return (final);
	return (NULL);
}

int				customs_officer(char *tmp2, int len, char *surface, int *o)
{
	int i;

	i = 0;
	if (ft_strchr(tmp2, '*') || ft_strchr(tmp2, '[') ||
			ft_strchr(tmp2, '?') || (access(tmp2, F_OK) == 0))
	{
		if (!surface[len] || add_one(surface, len))
			*o += 1;
		return (0);
	}
	return (1);
}
