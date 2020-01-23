/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 09:53:02 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 12:56:37 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tools.h"

int						ft_match(long long a, long long b)
{
	if (a == b)
		return (0);
	return (1);
}

long long				ft_getdivisor(long long nbr)
{
	long long	divisor;

	divisor = 1;
	while (nbr / divisor >= 1000)
		divisor *= 1000;
	return (divisor);
}

int						ft_isnumeric(char *str)
{
	if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	return (*str ? 0 : 1);
}

int						ft_checkdico(t_list *ldico)
{
	long long testvalue;

	testvalue = 0;
	while (testvalue < 20)
	{
		if (!ft_listfind(ldico, &testvalue, &ft_match))
			return (0);
		testvalue++;
	}
	while (testvalue <= 100)
	{
		if (!ft_listfind(ldico, &testvalue, &ft_match))
			return (0);
		testvalue += 10;
	}
	testvalue = 1000;
	if (!ft_listfind(ldico, &testvalue, &ft_match))
		return (0);
	testvalue = 1000000;
	if (!ft_listfind(ldico, &testvalue, &ft_match))
		return (0);
	testvalue = 1000000000;
	if (!ft_listfind(ldico, &testvalue, &ft_match))
		return (0);
	return (1);
}
