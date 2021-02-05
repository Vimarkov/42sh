/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:58:56 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/05 11:00:19 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

int		ft_ntsarr_len(char **ntsarr)
{
	int	i;

	if (!ntsarr)
		return (0);
	i = 0;
	while (ntsarr[i])
		i++;
	return (i);
}
