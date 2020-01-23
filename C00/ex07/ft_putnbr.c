/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 12:09:11 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 12:12:38 by jgambard    ###    #+. /#+    ###.fr     */
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
	int		divisor;

	divisor = 1;
	while ((nb / 10) / divisor)
		divisor = divisor * 10;
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putchar(((nb / divisor) * -1) + '0');
		nb = nb % divisor;
		nb = nb * -1;
		divisor = divisor / 10;
	}
	while (divisor)
	{
		ft_putchar(nb / divisor + '0');
		nb = nb % divisor;
		divisor = divisor / 10;
	}
}
