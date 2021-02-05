/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordtab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:36:06 by kdumarai          #+#    #+#             */
/*   Updated: 2018/07/04 02:52:33 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDTAB_H
# define WORDTAB_H

# include <string.h>

char	**ft_tabnew(void);
void	ft_puttab(char **tab, char *tabname);
void	ft_puttab_fd(char **tab, char *tabname, int outfd);
size_t	ft_tablen(char **tab);
void	ft_tabsort(char **tab);
char	**ft_tabjoin(char **tab1, char **tab2);
int		ft_tabadd(char ***wt, char **wt2);
int		ft_tabaddstr(char ***wt, char *newstr);
char	**ft_tabdup(char **src);
void	ft_tabfree(char ***tab);

#endif
