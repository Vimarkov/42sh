/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:59:48 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/11 17:27:23 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char	*ft_strappf(char *dst, char *src)
{
	char	*new;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlenp(dst);
	src_len = ft_strlenp(src);
	if (src == NULL)
		return (NULL);
	if ((new = ft_strnew(dst_len + src_len)) == NULL)
		return (NULL);
	if (dst_len != 0)
		ft_strcat(new, dst);
	ft_strcat(new, src);
	ft_strdel(&dst);
	ft_strdel(&src);
	return (new);
}
