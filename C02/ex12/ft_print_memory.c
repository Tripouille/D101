/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_memory.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 22:10:24 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 21:37:38 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnpchar(char *str, int number)
{
	int		i;

	i = -1;
	while (++i < number)
	{
		ft_putchar((*str >= 32 && *str <= 126) ? *str : '.');
		str++;
	}
}

void	ft_printhexa(char *str, int number)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (i < number)
		{
			ft_putchar(*str / 16 < 10 ? *str / 16 + '0' : *str / 16 + 'W');
			ft_putchar(*str % 16 < 10 ? *str++ % 16 + '0' : *str++ % 16 + 'W');
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
	}
}

void	ft_getaddr(unsigned long num, unsigned int *tab)
{
	if (!num)
		return ;
	ft_getaddr(num / 16, tab + 1);
	*tab = (num % 16 < 10 ? num % 16 + '0' : num % 16 + 'W');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		taddr[15];
	int					j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 15)
			taddr[j++] = '0';
		ft_getaddr((unsigned long)(addr + i), taddr);
		while (j > 0)
			ft_putchar(taddr[--j]);
		ft_printnpchar(": ", 2);
		ft_printhexa(addr + i, size - i >= 16 ? 16 : size - i);
		ft_printnpchar(addr + i, size - i >= 16 ? 16 : size - i);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
