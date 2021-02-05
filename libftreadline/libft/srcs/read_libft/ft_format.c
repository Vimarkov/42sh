/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:12:15 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/09 12:19:12 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char		*ft_format(const char *s, ...)
{
	va_list	va;
	char	*fs;

	va_start(va, s);
	fs = ft_format_internal(s, &va);
	va_end(va);
	return (fs);
}
