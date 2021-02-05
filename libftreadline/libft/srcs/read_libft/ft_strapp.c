/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:15:25 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/07 11:00:06 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char	*ft_strapp(char *dst, char *src)
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
	return (new);
}
