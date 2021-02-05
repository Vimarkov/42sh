/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:34:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 03:34:03 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

char		*get_basedir(const char *f_path);
const char	*get_name_from_path(const char *path);
char		*get_name_from_path_2(const char *path);
char		*get_elem_path(const char *d_path, char *name);

#endif
