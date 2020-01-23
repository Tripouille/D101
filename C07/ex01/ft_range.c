/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 17:31:01 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 15:22:49 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	long	i;
	long	lmin;
	long	lmax;

	lmin = min;
	lmax = max;
	if (lmin >= lmax)
		return (0);
	tab = malloc(sizeof(*tab) * (lmax - lmin));
	if (!tab)
		return (0);
	i = -1;
	while (++i < lmax - lmin)
		tab[i] = lmin + i;
	return (tab);
}
