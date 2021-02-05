/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:23:11 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/12 13:37:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char	**ft_ntsarr_new(void)
{
	char	**new;

	new = NULL;
	new = (char**)malloc(sizeof(char*));
	new[0] = NULL;
	return (new);
}
