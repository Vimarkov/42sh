/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:18:34 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/05 17:23:55 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree	*ft_btnew(void *data, size_t data_size)
{
	t_btree	*ret;

	if (!(ret = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	ft_bzero(ret, sizeof(t_btree));
	if (data)
	{
		if (!(ret->data = malloc(data_size)))
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->data, data, data_size);
		ret->data_size = data_size;
	}
	return (ret);
}
