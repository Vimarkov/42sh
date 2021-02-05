/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_quit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 02:30:12 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/14 05:01:36 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTRL_QUIT_H
# define FTRL_QUIT_H

typedef struct	s_quitmsgdat
{
	char		*msg;
	int			fd;
	char		reserved_pad[4];
}				t_quitmsgdat;

#endif
