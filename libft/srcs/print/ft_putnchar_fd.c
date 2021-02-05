/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:37:48 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/25 16:39:05 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnchar_fd(char c, size_t n, int fd)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
	{
		while (n--)
			(void)write(fd, &c, 1);
		return ;
	}
	(void)ft_memset(str, c, n);
	str[n] = '\0';
	ft_putstr_fd(str, fd);
	free(str);
}
