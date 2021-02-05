/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:16:26 by echojnow          #+#    #+#             */
/*   Updated: 2018/08/13 20:46:14 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LIBFT_H
# define READ_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <dirent.h>
# include <errno.h>

# include "libft.h"

/*
** String
*/
size_t			ft_strlenp(const char *s);
char			*ft_strapp(char *dst, char *src);
char			*ft_strappf(char *dst, char *src);
char			*ft_strappc(char *dst, char src);
char			*ft_strappcf(char *dst, char src);
char			**ft_readsplit(char *s, char c, int dont_escape);

char			*ft_format_internal(const char *s, va_list *va);
char			*ft_format(const char *s, ...);

/*
** Null Terminated String Array
*/
char			**ft_ntsarr_new(void);
char			**ft_ntsarr_push(char ***ntsarr, char *s);
char			**ft_ntsarr_app(char ***ntsarr, char *s);
int				ft_ntsarr_len(char **ntsarr);
void			ft_ntsarr_free(char ***ntsarr);
void			ft_ntsarr_print(char **ntsarr, int newline);

void			ft_put(const char *s, ...);

/*
** File
*/
# define BUFF_SIZE 32

typedef struct	s_vars
{
	int		i;
	int		end;
	int		read_val;
	char	readbuf[BUFF_SIZE + 1];
}				t_vars;

int				ft_gnl(const int fd, char **line);

#endif
