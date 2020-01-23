/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_int_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/05 03:36:11 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 03:36:16 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		lower;

	if (size < 2)
		return ;
	while (--size)
	{
		lower = 0;
		i = 0;
		while (++i <= size)
		{
			if (*(tab + i) < *(tab + lower))
				lower = i;
		}
		if (lower)
			ft_swap(tab, tab + lower);
		tab++;
	}
}
