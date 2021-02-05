/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soudeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:03:55 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/07 04:07:54 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICLUCAS_H
# define VICLUCAS_H
# include <sys/stat.h>
# include <stdlib.h>

typedef struct		s_tabv
{
	int		flag1;
	int		flag2;
	int		j;
	int		i;
	int		o;
	char	**board;
}					t_tabv;

char				**ft_free_db_tab(char **av);
char				*ft_souder(char *s1, char *s2, char *s3);
int					ft_error(char *s1, char *name);
void				ft_quotes_check(t_tabv *x, char c);
char				*ft_acces(char *s);
void				print_db(char **board);
void				ft_free_thoses(char **s1, char **s2, char **s3, char **s4);
#endif
