/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ultimate_range.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 11:27:57 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 14:51:27 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	long	i;
	long	lmin;
	long	lmax;

	lmin = min;
	lmax = max;
	if (lmin >= lmax)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(**range) * (lmax - lmin));
	if (!*range)
		return (-1);
	i = -1;
	while (lmin + (++i) < lmax)
		(*range)[i] = lmin + i;
	return (lmax - lmin);
}
