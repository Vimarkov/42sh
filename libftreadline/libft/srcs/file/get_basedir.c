/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_basedir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:35:26 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/03 05:26:08 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_basedir(const char *f_path)
{
	char			*ret;
	char			*rchr_ret;
	size_t			ret_len;

	if (!f_path)
		return (NULL);
	if (!(rchr_ret = ft_strrchr(f_path, '/')))
		return (ft_strdup("."));
	if ((ret_len = (unsigned long)rchr_ret - (unsigned long)f_path) == 0)
		ret_len = 1;
	if (!(ret = ft_strnew(ret_len)))
		return (NULL);
	ft_strncpy(ret, f_path, ret_len);
	return (ret);
}
