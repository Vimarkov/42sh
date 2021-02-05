/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttabnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 01:53:40 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/25 04:05:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_uint8		ft_ttabnew(t_tab *vtab, size_t data_size)
{
	ft_bzero(vtab, sizeof(t_tab));
	if (!(vtab->data = malloc(data_size * MTAB_DEFAULT_BUFFLEN)))
		return (FALSE);
	vtab->data_size = data_size;
	vtab->buff_size = MTAB_DEFAULT_BUFFLEN * data_size;
	return (TRUE);
}
