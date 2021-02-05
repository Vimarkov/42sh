/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:02 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 23:52:38 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr_internal.h"

int		ft_tstrncat(t_str *vstr, const char *add, size_t len)
{
	return (tstrncat_core(vstr, add, (ssize_t)len));
}
