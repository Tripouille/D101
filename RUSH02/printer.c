/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printer.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 19:13:59 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:40:06 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printer.h"

void				ft_displayword(t_list *ldico, long long nbr)
{
	ft_putstr(ft_listfind(ldico, &nbr, &ft_match)->dico->writing);
}

void				ft_displaypart(t_list *ldico, int h, int d, int u)
{
	if (h)
	{
		ft_displayword(ldico, h);
		ft_putstr(" ");
		ft_displayword(ldico, 100);
		if (d || u)
			ft_putstr(" ");
	}
	if (d < 2 && (u || d))
		ft_displayword(ldico, d * 10 + u);
	else
	{
		if (d)
			ft_displayword(ldico, d * 10);
		if (u)
		{
			ft_putstr(" ");
			ft_displayword(ldico, u);
		}
	}
}

void				ft_printer(t_list *ldico, long long nbr)
{
	long long			divisor;
	long long			tmp;

	if (nbr == 0)
	{
		ft_displayword(ldico, 0);
		ft_putstr("\n");
		return ;
	}
	divisor = ft_getdivisor(nbr);
	while (divisor >= 1)
	{
		tmp = nbr / divisor;
		ft_displaypart(ldico, tmp / 100, tmp % 100 / 10, tmp % 10);
		nbr %= divisor;
		if (divisor > 1 && tmp)
		{
			ft_putstr(" ");
			ft_displayword(ldico, divisor);
			if (nbr)
				ft_putstr(" ");
		}
		divisor /= 1000;
	}
	ft_putstr("\n");
}
