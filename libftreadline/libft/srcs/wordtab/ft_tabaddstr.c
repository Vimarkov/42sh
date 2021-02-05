/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 01:00:54 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/11 01:28:27 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabaddstr(char ***wt, char *newstr)
{
	char	*nt[2];

	if (!wt || !newstr)
		return (FALSE);
	nt[0] = newstr;
	nt[1] = NULL;
	return (ft_tabadd(wt, nt));
}
