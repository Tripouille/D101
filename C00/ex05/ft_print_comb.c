/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 15:06:59 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 15:40:32 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomb(char n1, char n2, char n3)
{
	ft_putchar(n1);
	ft_putchar(n2);
	ft_putchar(n3);
}

void	ft_print_comb(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0' - 1;
	while (++n1 <= '7')
	{
		n2 = n1;
		while (++n2 <= '8')
		{
			n3 = n2;
			while (++n3 <= '9')
			{
				ft_putcomb(n1, n2, n3);
				if (!(n1 == '7' && n2 == '8' && n3 == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
