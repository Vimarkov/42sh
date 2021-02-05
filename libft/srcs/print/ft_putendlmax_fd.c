/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlmax_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:04:42 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/28 18:04:27 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putendlmax_fd(const char *s, size_t len, int fd)
{
	size_t	ret;

	ret = ft_putstrmax_fd(s, len, fd);
	if (write(fd, "\n", 1) > 0)
		ret++;
	return (ret);
}
