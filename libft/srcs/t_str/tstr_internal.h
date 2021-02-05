/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:13:41 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 17:04:15 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSTR_INTERNAL_H
# define TSTR_INTERNAL_H

# include <unistd.h>
# include "libft.h"

int		tstrncat_core(t_str *vstr, const char *add, ssize_t len);
int		tstrncpy_core(t_str *vstr, const char *add, ssize_t len);
int		ft_tstr_cpycore(t_str *vstr, size_t addlen);

#endif
