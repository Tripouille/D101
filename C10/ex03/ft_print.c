/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 05:50:11 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 05:52:44 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstrn(char *str, int n)
{
	write(1, "|", 1);
	while (n-- > 0)
	{
		ft_putchar((*str >= 32 && *str <= 126) ? *str : '.');
		str++;
	}
	write(1, "|", 1);
}

void	ft_printhexa(char *str, int number, int option)
{
	int		i;

	i = -1;
	while (++i <= 16)
	{
		if (option)
			write(1, (!(i % 8) ? "  " : " "), 2);
		else
			write(1, " ", 1);
		if (i < number)
		{
			ft_putchar(*str / 16 < 10 ? *str / 16 + '0' : *str / 16 + 'W');
			ft_putchar(*str % 16 < 10 ? *str++ % 16 + '0' : *str++ % 16 + 'W');
		}
		else if (i != 16)
			write(1, "  ", 2);
	}
}

void	ft_printoffset(int offset, int option)
{
	char			tab[8];
	int				i;

	i = 0;
	while (i < 8)
		tab[i++] = '0';
	while (i-- > 0)
	{
		tab[i] = offset % 16 < 10 ? offset % 16 + '0' : offset % 16 + 'W';
		offset /= 16;
	}
	i = option ? 0 : 1;
	while (i < 8)
		ft_putchar(tab[i++]);
}
