/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_non_printable.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 13:21:03 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 19:59:17 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr_non_printable(char *str)
{
	int		tmp;

	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			ft_putchar(*str++);
		else
		{
			ft_putchar('\\');
			if (*str < 0)
			{
				tmp = *str + 256;
				ft_putchar(tmp / 16 < 10 ? tmp / 16 + '0' : tmp / 16 + 'W');
				ft_putchar(tmp % 16 < 10 ? tmp % 16 + '0' : tmp % 16 + 'W');
			}
			else
			{
				ft_putchar(*str / 16 < 10 ? *str / 16 + '0' : *str / 16 + 'W');
				ft_putchar(*str % 16 < 10 ? *str % 16 + '0' : *str % 16 + 'W');
			}
			str++;
		}
	}
}
