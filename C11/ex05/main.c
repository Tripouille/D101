/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 17:39:07 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 10:17:20 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "ft_put.h"
#include "ft_calculate.h"

int			main(int ac, char **av)
{
	t_operator		calc[6];
	int				number1;
	int				number2;

	if (ac != 4)
		return (0);
	if (av[2][1])
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	number1 = ft_atoi(av[1]);
	number2 = ft_atoi(av[3]);
	if (!number2 && *(av[2]) == '/')
		ft_putstr("Stop : division by zero");
	else if (!number2 && *(av[2]) == '%')
		ft_putstr("Stop : modulo by zero");
	else
	{
		ft_calcinit(calc);
		ft_putnbr(ft_calculate(number1, number2, *(av[2]), calc));
	}
	ft_putchar('\n');
	return (0);
}
