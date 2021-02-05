/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:36:44 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/29 00:36:54 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_elem_path(const char *d_path, char *name)
{
	char			*ret;

	if (!d_path || !name)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(d_path) + ft_strlen(name) + 1)))
		return (NULL);
	ft_strcat(ret, d_path);
	ft_strcat(ret, "/");
	ft_strcat(ret, name);
	return (ret);
}
