/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttabnew_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 01:53:40 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/25 04:04:50 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

inline t_tab	ft_ttabnew_cpy(size_t data_size)
{
	t_tab	ret;

	(void)ft_ttabnew(&ret, data_size);
	return (ret);
}
