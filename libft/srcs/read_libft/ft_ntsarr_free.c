/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:57:36 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/06 22:10:07 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

void	ft_ntsarr_free(char ***ntsarr)
{
	int i;

	i = -1;
	while ((*ntsarr)[++i])
		free((*ntsarr)[i]);
	free(*ntsarr);
	*ntsarr = NULL;
}
