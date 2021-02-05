/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_fsfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:26:34 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 18:34:20 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include "ftrl_linux.h"
#include "ftrl_internal.h"

static int			is_exec(const char *d_path, char *name, int folder)
{
	struct stat		st;
	char			*elem_path;
	int				ret;

	if (!d_path || !name || !(elem_path = get_elem_path(d_path, name)))
		return (FALSE);
	ret = FALSE;
	if (stat(elem_path, &st) != -1 && (st.st_mode & S_IXUSR
		|| st.st_mode & S_IXGRP || st.st_mode & S_IXOTH)
		&& S_ISDIR(st.st_mode) == folder)
		ret = TRUE;
	ft_strdel(&elem_path);
	return (ret);
}

inline static char	*get_visible_str(struct dirent *dird, char *basedir)
{
	char	*ret;
	int		isexec;

	if (dird->d_type == DT_DIR)
		return (NULL);
	isexec = is_exec(basedir, dird->d_name, NO);
	if (!(ret = ft_strnew(dnamlen(dird) + (size_t)isexec)))
		return (NULL);
	(void)ft_strcpy(ret, dird->d_name);
	if (isexec)
		ret[dnamlen(dird)] = '*';
	return (ret);
}

inline static void	search_files_add(struct dirent *dird,
									char *basedir,
									t_list **ret)
{
	t_list	*new;
	t_acres	newcontent;

	ft_bzero((void*)&newcontent, sizeof(t_acres));
	if (!(newcontent.str = ft_strnew(dnamlen(dird) + 1)))
		return ;
	(void)ft_strcpy(newcontent.str, dird->d_name);
	if (dird->d_type != DT_LNK)
		(void)ft_strcpy(newcontent.str + dnamlen(dird),
			(dird->d_type == DT_DIR) ? "/" : " ");
	newcontent.visible_str = get_visible_str(dird, basedir);
	if (!(new = ft_lstnew((void*)&newcontent, sizeof(t_acres))))
	{
		ft_strdel(&newcontent.visible_str);
		free(newcontent.str);
		return ;
	}
	ft_lstadd(ret, new);
}

t_list				*search_files_begin(const char *f_path,
										char *s_dir,
										int exec)
{
	t_list			*ret;
	DIR				*dirp;
	struct dirent	*dird;
	char			*basedir;
	const char		*name;

	basedir = (!s_dir) ? get_basedir(f_path) : s_dir;
	name = get_name_from_path(f_path);
	dirp = opendir(basedir);
	ret = NULL;
	while (dirp && (dird = readdir(dirp)))
	{
		if (!ft_strequ(dird->d_name, ".") && !ft_strequ(dird->d_name, "..")
			&& ((!exec && ft_strstart(dird->d_name, name))
			|| (exec && ft_strstart(dird->d_name, name)
			&& is_exec(s_dir, dird->d_name, FALSE))))
			search_files_add(dird, basedir, &ret);
	}
	if (dirp)
		(void)closedir(dirp);
	if (!s_dir)
		ft_strdel(&basedir);
	return (ret);
}
