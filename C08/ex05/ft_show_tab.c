/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_show_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 06:00:17 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 06:28:11 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_stock_str.h"
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
		ft_putnbr(nb < 0 ? -(nb / 10) : (nb / 10));
	ft_putchar((nb < 0 ? -(nb % 10) : nb % 10) + '0');
}

void	ft_putstricr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par && (*par).str)
	{
		ft_putstricr((*par).str);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_putstricr((*par).copy);
		par++;
	}
}
