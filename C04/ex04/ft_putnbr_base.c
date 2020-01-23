/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 16:35:54 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 22:37:41 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_base_is_valid(char *base)
{
	int		len;
	int		i;

	len = -1;
	if (!base)
		return (0);
	while (base[++len])
	{
		i = 1;
		while (base[len + i] && (base[len] != base[len + i]))
			i++;
		if (base[len + i] || base[len] == '-' || base[len] == '+')
			return (0);
	}
	return (len);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	int		divisor;
	long	lnbr;

	base_size = ft_base_is_valid(base);
	if (base_size < 2)
		return ;
	lnbr = nbr;
	if (lnbr < 0)
	{
		ft_putchar('-');
		lnbr = -lnbr;
	}
	divisor = 1;
	while ((lnbr / base_size) / divisor)
		divisor *= base_size;
	while (divisor)
	{
		ft_putchar(base[lnbr / divisor]);
		lnbr %= divisor;
		divisor /= base_size;
	}
}
