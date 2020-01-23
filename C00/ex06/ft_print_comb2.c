/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 17:30:49 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 18:04:39 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		nbr1;
	int		nbr2;

	nbr1 = -1;
	while (++nbr1 <= 98)
	{
		nbr2 = nbr1;
		while (++nbr2 <= 99)
		{
			ft_putchar(nbr1 / 10 + '0');
			ft_putchar(nbr1 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(nbr2 / 10 + '0');
			ft_putchar(nbr2 % 10 + '0');
			if (!(nbr1 == 98 && nbr2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
