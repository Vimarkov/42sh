/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_termcap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:36:45 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 14:08:19 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTRL_TERMCAP_H
# define FTRL_TERMCAP_H

/*
** Termcaps
** --------
**
** Preprocessor directive for Linux compatibility
*/

# ifdef __linux__
#  include <term.h>
#  include <curses.h>
# else
#  include <termcap.h>
# endif

/*
** structs for termcaps
*/

typedef struct	s_keys
{
	char	*leftk;
	char	*rightk;
	char	*upk;
	char	*downk;
	char	*homek;
	char	*endk;
	char	*delk;
	char	*clrk;
	char	*tabk;
}				t_keys;

typedef struct	s_mov
{
	char	*leftm;
	char	*rightm;
	char	*upm;
	char	*downm;
	char	*cecap;
	char	*crcap;
	char	*dlargcap;
	char	*dlcap;
}				t_mov;

/*
** my custom termcap functions
*/

int				putcf(int c);

int				outcap_fd(char *name, int fd);
int				outcap(char *name);
int				outcapstr(char *cstr);
int				outcap_arg_fb(char *cstr, char *fb, int arg, int affcnt);

#endif
