/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_combn.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 18:55:22 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 23:18:59 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putcomb(int tab[9], int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putchar(tab[i++] + '0');
}

void		ft_print_combn(int n)
{
	int		tab[9];
	int		i;

	i = -1;
	while (++i < n)
		tab[i] = i;
	while (tab[0] <= 10 - n)
	{
		ft_putcomb(tab, n);
		i = 0;
		tab[n - 1]++;
		while (tab[0] <= 10 - n && tab[(n - 1) - i] > 9 - i)
			tab[n - 1 - (++i)]++;
		while (i)
		{
			tab[(n - i)] = tab[(n - i) - 1] + 1;
			i--;
		}
		if (tab[0] <= 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}
