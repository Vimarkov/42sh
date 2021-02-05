/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_dev.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:53:36 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/16 17:27:36 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTRL_DEV_H
# define FTRL_DEV_H

# include "ftrl_data.h"

/*
** struct for ac results
*/

typedef struct	s_acres
{
	char	*visible_str;
	char	*str;
}				t_acres;

/*
** bltn functions
*/

t_list			*get_ac_result_bltn(char *line, t_cursor *csr);
char			*show_ac_result_bltn(t_list **res);

/*
** lst mgmt functions
*/

void			ft_aclst_rmdups(t_list **lst);
void			ft_acres_free(void *content, size_t size);
int				ft_acres_sortalpha(t_list *a, t_list *b);

#endif
