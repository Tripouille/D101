/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 12:05:15 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:18:38 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H
# include <unistd.h>
# include "ft_list.h"

void	ft_putstr(char *str);
int		ft_putstrerror(char *str);
int		ft_error(t_list *ldico, char *msg);
int		ft_succes(t_list *ldico);

#endif
