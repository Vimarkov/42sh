/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:29:43 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 18:35:07 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftrl_linux.h"

#ifdef __linux__

size_t		dnamlen(struct dirent *dird)
{
	return (ft_strlen(dird->d_name));
}

#else

size_t		dnamlen(struct dirent *dird)
{
	return (dird->d_namlen);
}

#endif
