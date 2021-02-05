/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:56:19 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/08 15:28:38 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

static int	readline(char **lb, const int fd, t_vars *v)
{
	*lb = ft_strappf(*lb, ft_strsub((const char*)v->readbuf, v->i,
				(v->end - v->i)));
	ft_strclr(v->readbuf);
	if ((v->read_val = read(fd, v->readbuf, BUFF_SIZE)) == 0)
	{
		if (*lb != NULL && ft_strcmp(*lb, "") != 0)
			v->read_val = 1;
		return (1);
	}
	else if (v->read_val < 0)
		return (-1);
	else if (v->read_val > 0)
		v->read_val = 1;
	v->i = 0;
	v->end = -1;
	return (0);
}

int			ft_gnl(const int fd, char **line)
{
	static t_vars	v = { .i = 0, .end = 0, .read_val = 0 };
	int				should_break;
	char			*lb;

	if (line == NULL)
		return (-1);
	lb = NULL;
	v.end = v.i - 1;
	while (v.readbuf[++(v.end)] != '\n')
	{
		if (v.end > BUFF_SIZE - 1 || v.readbuf[v.end] == 0)
		{
			if ((should_break = readline(&lb, fd, &v)) == 1)
				break ;
			else if (should_break == -1)
				return (-1);
		}
	}
	lb = ft_strappf(lb, ft_strsub(v.readbuf, v.i, (v.end - v.i)));
	*line = ft_strdup(lb);
	ft_strdel(&lb);
	v.i = v.end + 1;
	return ((v.read_val > 0) ? 1 : v.read_val);
}
