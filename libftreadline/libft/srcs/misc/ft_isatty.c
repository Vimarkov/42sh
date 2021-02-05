/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isatty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:57:15 by kdumarai          #+#    #+#             */
/*   Updated: 2018/01/12 16:59:27 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <termios.h>

int		ft_isatty(int fildes)
{
	int				errno_bak;
	int				tcret;
	struct termios	termios_s;
	int				ret;

	errno_bak = errno;
	tcret = tcgetattr(fildes, &termios_s);
	ret = (tcret != -1 && errno != ENOTTY);
	errno = errno_bak;
	return (ret);
}
