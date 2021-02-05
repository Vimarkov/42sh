/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:58:28 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/25 03:55:57 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tstrdel(t_str *vstr)
{
	if (!vstr)
		return ;
	free(vstr->s);
	ft_bzero(vstr, sizeof(t_str));
}
