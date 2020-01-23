/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 12:03:03 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:18:38 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_putstrerror(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (-1);
}

int		ft_error(t_list *ldico, char *msg)
{
	ft_putstrerror(msg);
	ft_list_purge(&ldico);
	return (-1);
}

int		ft_succes(t_list *ldico)
{
	ft_list_purge(&ldico);
	return (0);
}
