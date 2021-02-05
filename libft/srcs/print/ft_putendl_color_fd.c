/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:36:45 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/12 22:17:51 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_color_fd(char const *s, char const *ec, int fd)
{
	ft_putstr_fd(ec, fd);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(DEFAULTCLR, fd);
}
