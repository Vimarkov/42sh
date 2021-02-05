/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:02 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 20:19:29 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr_internal.h"

inline int		ft_tstrcat(t_str *vstr, const char *add)
{
	return (tstrncat_core(vstr, add, -1));
}
