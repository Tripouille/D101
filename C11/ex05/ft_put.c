/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 12:47:01 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 10:13:38 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if (nb >= 10 || nb <= -10)
		ft_putnbr(nb < 0 ? -(nb / 10) : (nb / 10));
	ft_putchar(nb < 0 ? -(nb % 10) + '0' : (nb % 10) + '0');
}
