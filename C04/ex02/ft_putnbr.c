/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 12:47:01 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 13:16:43 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr(nb < 0 ? -(nb / 10) : (nb / 10));
		ft_putnbr(nb < 0 ? -(nb % 10) : (nb % 10));
	}
	else
		ft_putchar((nb < 0 ? -nb : nb) + '0');
}
