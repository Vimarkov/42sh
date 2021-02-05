/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_insert_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:37:55 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 04:51:52 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"
#include "ftrl_quit.h"

static void		quit_simplefree(void *data)
{
	if (!data)
		return ;
	free(data);
}

static void		quit_msgfree(void *data)
{
	free((void*)((t_quitmsgdat*)data)->msg);
	free(data);
}

static void		quit_putmsg(void *data)
{
	t_quitmsgdat	*msg;

	if (!(msg = (t_quitmsgdat*)data))
		return ;
	ft_putendlsec_fd(msg->msg, msg->fd);
}

t_uint8			ftrl_insert_msg(char *msg, int fd, t_uint8 free_msg)
{
	t_quitmsgdat	*data;
	void			(*free_func)(void *);

	if (!(data = (t_quitmsgdat*)malloc(sizeof(t_quitmsgdat))))
		return (FALSE);
	data->msg = msg;
	data->fd = fd;
	free_func = (free_msg) ? &quit_msgfree : &quit_simplefree;
	if (!quit_with_reason(kAbortReload, &quit_putmsg, data, free_func))
	{
		free(data);
		return (FALSE);
	}
	return (TRUE);
}
