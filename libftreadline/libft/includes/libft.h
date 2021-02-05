/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:58:20 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/13 03:36:14 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stddef.h>

# include "ft_int.h"

# include "mem.h"
# include "str.h"
# include "wordtab.h"
# include "char.h"
# include "t_str.h"
# include "t_tab.h"
# include "nbr.h"
# include "btree.h"
# include "list.h"
# include "print.h"
# include "misc.h"
# include "file.h"
# include "get_next_line.h"
# include "viclucas.h"

/*
** ANSI Colors
*/

# define BLACKCLR			"\033[0;30m"
# define REDCLR				"\033[0;31m"
# define GREENCLR			"\033[0;32m"
# define YELLOWCLR			"\033[0;33m"
# define BLUECLR			"\033[0;34m"
# define PURPLECLR			"\033[0;35m"
# define CYANCLR			"\033[0;36m"
# define WHITECLR			"\033[0;37m"
# define DEFAULTCLR			"\033[0;39m"

# define LIGHTBLACKCLR		"\033[1;30m"
# define LIGHTREDCLR		"\033[1;31m"
# define LIGHTGREENCLR		"\033[1;32m"
# define LIGHTYELLOWCLR		"\033[1;33m"
# define LIGHTBLUECLR		"\033[1;34m"
# define LIGHTPURPLECLR		"\033[1;35m"
# define LIGHTCYANCLR		"\033[1;36m"
# define LIGHTWHITECLR		"\033[1;37m"

/*
** TRUE/YES and FALSE/NO
*/

# define YES				1
# define NO					0
# define TRUE				1
# define FALSE				0

/*
** size struct (width/height)
*/

typedef struct		s_size
{
	size_t		width;
	size_t		height;
}					t_size;

/*
** pt struct (x/y -- same as t_size)
*/

typedef struct		s_point32
{
	unsigned int	x;
	unsigned int	y;
}					t_point32;

typedef struct		s_point64
{
	unsigned long	x;
	unsigned long	y;
}					t_point64;

typedef t_point64	t_point;

/*
** bool type
*/

typedef enum		e_bool
{
	kTrue,
	kFalse
}					t_bool;

#endif
