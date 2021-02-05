/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:43:45 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/25 04:08:10 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint8		ft_tstrnew(t_str *vstr)
{
	vstr->s = ft_strnew(VSTR_DEFAULT_BUFFLEN);
	vstr->len = 0;
	vstr->bufflen = (vstr->s) ? VSTR_DEFAULT_BUFFLEN : 0;
	return ((vstr->s != NULL));
}
