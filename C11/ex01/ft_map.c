/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:44:57 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 16:18:29 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*map;
	int		i;

	if (length <= 0 || !(map = malloc(sizeof(*tab) * length)))
		return (0);
	i = -1;
	while (++i < length)
		map[i] = (*f)(tab[i]);
	return (map);
}
