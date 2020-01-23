/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calculate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 20:54:28 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 10:16:56 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_calculate.h"
#include "ft_calc.h"

int			ft_calculate(int a, int b, char op, struct s_operator *optab)
{
	while (op != optab->symb && optab->op)
		optab++;
	return (optab->op ? optab->op(a, b) : 0);
}

void		ft_calcinit(struct s_operator *calc)
{
	calc[0].symb = '+';
	calc[0].op = &ft_add;
	calc[1].symb = '-';
	calc[1].op = &ft_sub;
	calc[2].symb = '*';
	calc[2].op = &ft_mul;
	calc[3].symb = '/';
	calc[3].op = &ft_div;
	calc[4].symb = '%';
	calc[4].op = &ft_mod;
	calc[5].op = 0;
}
