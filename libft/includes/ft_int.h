/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:09:03 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/01 23:50:08 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <stddef.h>

/*
** 8-bit ones
*/

typedef unsigned char	t_uint8;
typedef char			t_int8;

/*
** 32-bit ones
*/

typedef unsigned int	t_uint32;
typedef int				t_int32;

/*
** 64-bit ones
*/

typedef unsigned long	t_uint64;
typedef long			t_int64;

/*
** ptr
*/

typedef t_uint64		t_uintptr;
typedef ptrdiff_t		t_intptr;

/*
** characters
*/

typedef int				t_wchar;

#endif
