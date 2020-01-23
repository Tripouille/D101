/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 09:53:56 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:52:15 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include "ft_list.h"

int						ft_match(long long a, long long b);
long long				ft_getdivisor(long long nbr);
int						ft_isnumeric(char *str);
int						ft_checkdico(t_list *ldico);

#endif
