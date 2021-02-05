/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:20:56 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/14 05:11:48 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

char		**ft_glob_db(char **env, char *board)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	if (!board)
		return (env);
	while (env && env[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (env && env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i++] = ft_strdup(board);
	ret[i] = NULL;
	if (env)
		ft_free_db_tab(env);
	return (ret);
}

int			ft_get_on_top(char *line, int i, int c)
{
	while (line[i] != c && i > 0)
		i--;
	if (i != 0 && line[i] == c)
		i++;
	return (i);
}

char		*ft_add_path(char *path, char *test)
{
	char	*ret;

	if (!path)
	{
		ret = ft_strdup(test);
		free(test);
		return (ret);
	}
	if (!test)
		return (path);
	ret = ft_souder(path, test, "/");
	ft_strdel(&path);
	ft_strdel(&test);
	return (ret);
}

static char	*expend_surface(char *line, int *u, int before)
{
	int i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	*u = i + before;
	if (line[i])
		*u += 1;
	return (ft_strndup(line, i));
}

char		**surface_of_work(char *line, int *i)
{
	char	*tmp;
	char	**surface;
	int		u;

	surface = NULL;
	tmp = NULL;
	u = 0;
	if (!(surface = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	*i = ft_get_on_top(line, *i, ' ');
	surface[0] = expend_surface(line + *i, &u, *i);
	if (line[u] != '\0')
	{
		surface[1] = ft_strdup(line + u);
		surface[2] = NULL;
	}
	else
	{
		surface[1] = NULL;
		surface[2] = NULL;
	}
	return (surface);
}
