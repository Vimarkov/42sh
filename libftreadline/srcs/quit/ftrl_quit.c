/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:37:55 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/28 18:06:34 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"
#include "ftrl_quit.h"

t_uint8		quit_with_reason(t_abort reason,
								void (*func)(void *),
								void *data,
								void (*free_func)(void *))
{
	t_readline		*rl;

	if (!(rl = rl_latest_session(NO, NULL)))
		return (FALSE);
	rl->quit.reason = reason;
	rl->quit.func = func;
	rl->quit.func_data = data;
	rl->quit.free_func = free_func;
	if (!rl_set_timeout(YES, 0))
	{
		ft_bzero(&rl->quit, sizeof(t_quit));
		return (FALSE);
	}
	return (TRUE);
}

t_uint8		ftrl_quit(void)
{
	return (quit_with_reason(kAbortQuit, NULL, NULL, NULL));
}

t_uint8		ftrl_reload(void)
{
	return (quit_with_reason(kAbortReload, NULL, NULL, NULL));
}
