/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:49:05 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/28 04:42:04 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

t_readline		*rl_latest_session(t_uint8 set, t_readline *new_session)
{
	static t_readline	*session = NULL;

	if (set)
		session = new_session;
	return (session);
}
