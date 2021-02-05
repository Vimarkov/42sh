/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:18:29 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 04:44:10 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

static int		glob_compare_norm(t_glob *x, char *test, char *name,
		char **known)
{
	if ((x->plus = ft_globing_star(test, name, known, *x)) != -1)
	{
		x->i = x->i + ft_strlen(known[x->o]);
		x->u = x->u + x->plus;
		x->o += 1;
		if (test + x->i && !ft_strchr(test + x->i, '*'))
		{
			if (ft_strlen_glob(test + x->i) != ft_strlen(name + x->u))
				return (-1);
		}
		return (0);
	}
	else
		return (-1);
	return (0);
}

static int		glob_strnequ_compare(char *name, t_glob *x, char **known,
		char *test)
{
	x->i = x->i + ft_strlen(known[x->o]);
	x->u = x->u + ft_strlen(known[x->o]);
	x->o += 1;
	if (test + x->i && !ft_strchr(test + x->i, '*'))
	{
		if (ft_strlen_glob(test + x->i) != ft_strlen(name + x->u))
			return (-1);
	}
	return (0);
}

static int		glob_compare(char *test, char *name, char **known, t_glob *x)
{
	if (test[x->i] && test[x->i] != '*' && test[x->i] != '?' &&
			test[x->i] != '[')
		if (ft_strnequ(name + x->u, known[x->o], ft_strlen(known[x->o])))
		{
			if (glob_strnequ_compare(name, x, known, test) == -1)
				return (-1);
		}
		else if (x->i > 0 && test[x->i - 1] && test[x->i - 1] == '*')
		{
			if (glob_compare_norm(x, test, name, known) == -1)
				return (-1);
		}
		else
			return (-1);
	else
	{
		if (test[x->i] == '*')
			x->i++;
		else
		{
			x->i = ft_pass_theses(x->i, test);
			x->u += 1;
		}
	}
	return (0);
}

static char		**send_it(char *name, char **ret, char *test, char **known)
{
	t_glob	x;

	ft_bzero(&x, sizeof(t_glob));
	if (ft_strequ("..", name) || ft_strequ(".", name) || ft_strchr(name, '?'))
		return (ret);
	if (ft_strchr(test, '*') == NULL)
		if (ft_strlen_glob(test) != ft_strlen(name))
			return (ret);
	while (test[x.i] && known[x.o])
	{
		if (glob_compare(test, name, known, &x) < 0)
			return (ret);
	}
	ret = ft_glob_db(ret, name);
	return (ret);
}

char			**replace_char(char *surface, char *test, char **known)
{
	char			*prev;
	struct dirent	*g;
	DIR				*dir;
	char			**ret;
	int				o;

	ret = NULL;
	o = 0;
	if (!(prev = get_prev_string(surface)))
		prev = ft_strdup(".");
	if ((dir = opendir(prev)) == NULL)
	{
		ft_free_thoses(&prev, NULL, NULL, NULL);
		ft_tabfree(&known);
		return (NULL);
	}
	ft_strdel(&prev);
	while ((g = readdir(dir)) != NULL)
		ret = send_it(g->d_name, ret, test, known);
	closedir(dir);
	ft_tabfree(&known);
	return (ret);
}
