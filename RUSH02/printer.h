/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printer.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 19:39:11 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 16:35:45 by niglesia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H
# include "ft_list.h"
# include "tools.h"
# include "ft_put.h"

void				ft_displayword(t_list *ldico, long long nbr);
void				ft_displaypart(t_list *ldico, int h, int d, int u);
void				ft_printer(t_list *ldico, long long nbr);

#endif
