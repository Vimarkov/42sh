/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 14:44:39 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		rm_buff(t_list **bufflst, int fd)
{
	t_list			*curr;
	t_list			*prev;

	curr = *bufflst;
	prev = NULL;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				(*bufflst) = curr->next;
			ft_strdel((char**)&curr->content);
			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

static t_list	*get_buff(t_list **bufflst, int fd)
{
	t_list			*tmp;

	if (!bufflst)
		return (NULL);
	tmp = *bufflst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = *bufflst;
	if (!(*bufflst = ft_lstnew("", 1)))
		return (NULL);
	(*bufflst)->content_size = (size_t)fd;
	(*bufflst)->next = tmp;
	return (*bufflst);
}

static ssize_t	read_to_buff(int fd, char **stock)
{
	ssize_t			rb;
	ssize_t			rbt;
	char			buff[FT_GNL_BUFF_SIZE + 1];
	char			*tmp;

	if (!stock || !*stock)
		return (-1);
	rbt = (ft_strchr(*stock, '\n') == NULL && !ft_strcmp(*stock, "")) ? 0 : 1;
	rb = 1;
	while (rb > 0 && (rbt == 0 || !ft_strchr(*stock, '\n')))
	{
		rbt += (rb = read(fd, buff, FT_GNL_BUFF_SIZE));
		buff[rb] = '\0';
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, buff)))
		{
			if (tmp)
				free(tmp);
			return (-1);
		}
		free(tmp);
	}
	return (rbt);
}

int				get_next_line(int fd, char **line)
{
	static	t_list	*buffs;
	t_list			*buff;
	void			*tmp;
	ssize_t			retval;
	size_t			nli;

	nli = 0;
	if (line)
		*line = NULL;
	if (!line || fd < 0 || !(buff = get_buff(&buffs, fd)))
		return (-1);
	if ((retval = read_to_buff(fd, (char**)(&buff->content))) <= 0)
		return (rm_buff(&buffs, fd) ? (int)retval : (int)retval);
	while (((char*)(buff->content))[nli]
			&& ((char*)(buff->content))[nli] != '\n')
		nli++;
	*line = ft_strsub((char*)buff->content, 0, nli);
	nli += (((char*)(buff->content))[nli] != '\0');
	tmp = buff->content;
	buff->content = ft_strsub((char*)buff->content, (unsigned int)nli,
			ft_strlen(buff->content) - nli);
	free(tmp);
	return (1);
}
