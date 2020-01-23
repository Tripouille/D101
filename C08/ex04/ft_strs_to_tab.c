/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strs_to_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 14:01:54 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 11:15:52 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char					*ft_strdup(char *src)
{
	char	*dup;
	int		size;

	size = 0;
	while (src[size])
		size++;
	dup = malloc(sizeof(*dup) * (size + 1));
	if (!dup)
		return (0);
	dup[size] = 0;
	while (size--)
		dup[size] = src[size];
	return (dup);
}

int						ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str		*tab;
	int						i;

	if (!(tab = malloc(sizeof(*tab) * (ac + 1))))
		return (0);
	i = -1;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		if (!(tab[i].copy = ft_strdup(av[i])))
			return (0);
	}
	tab[i].str = 0;
	return (tab);
}
