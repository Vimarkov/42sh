/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:59:02 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/11 17:50:08 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char	*ft_strappc(char *dst, char src)
{
	char	*new;
	size_t	dst_len;

	dst_len = ft_strlenp(dst);
	if ((new = ft_strnew(dst_len + 1)) == NULL)
		return (NULL);
	if (dst_len != 0)
		ft_strcat(new, dst);
	new[dst_len] = src;
	return (new);
}
