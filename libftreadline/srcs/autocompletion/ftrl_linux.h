/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_linux.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:33:22 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 18:35:23 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTRL_LINUX_H
# define FTRL_LINUX_H

# include "libft.h"
# include <dirent.h>

size_t	dnamlen(struct dirent *dird);

#endif
