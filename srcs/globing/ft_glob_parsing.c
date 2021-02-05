/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:29:41 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 02:28:29 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

static void	norm_remove_some(char *s, int *i, int *n)
{
	while (s[*i] == '*')
	{
		(*i)++;
		(*n)++;
	}
}

int			remove_some(char *str, int ref)
{
	int i;
	int ret;
	int	n;

	n = 0;
	ret = 0;
	i = 0;
	while (str[i] && i < ref)
	{
		norm_remove_some(str, &i, &n);
		ref = ref + n;
		n = 0;
		if (str[i] == '[' && str[i + 1] && i + 1 < ref)
		{
			while (i < ref && str[i] && str[i] != ']')
			{
				i++;
				ret++;
			}
		}
		else
			i++;
	}
	return (ret);
}

int			ft_with_5f(char *str, char *o, int nb)
{
	int i;
	int j;

	j = 0;
	i = nb;
	while (o[j])
	{
		while (str[i])
		{
			if (str[i + 1] == '-' && str[i + 2])
				if (o[j] >= str[i] && o[j] <= str[i + 2])
				{
					ft_strdel(&o);
					ft_strdel(&str);
					return (1);
				}
			i += 3;
		}
		j++;
		i = 0;
	}
	ft_strdel(&str);
	ft_strdel(&o);
	return (-1);
}

int			ft_without_5f(char *str, char *test, int nb)
{
	int i;
	int j;

	j = 0;
	i = nb;
	while (test[j])
	{
		while (str[i])
		{
			if (str[i] == test[j])
			{
				ft_strdel(&test);
				ft_strdel(&str);
				return (1);
			}
			i++;
		}
		j++;
		i = 0;
	}
	ft_strdel(&test);
	ft_strdel(&str);
	return (-1);
}

int			ft_glob_parsing(char *str, char *o)
{
	if (!str || !str[0])
	{
		ft_strdel(&o);
		return (-1);
	}
	if (str[0] == '!')
	{
		if (ft_strchr(str, '-'))
			return (ft_with_5f(str, o, 1) * -1);
		else
			return (ft_without_5f(str, o, 1) * -1);
	}
	if (ft_strchr(str, '-'))
		return (ft_with_5f(str, o, 0));
	else
		return (ft_without_5f(str, o, 0));
}
