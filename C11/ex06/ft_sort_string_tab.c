/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_string_tab.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 21:35:50 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 23:49:28 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	if ((*s1 || *s2) && (*s1 == *s2))
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		ft_getsize(char **tab)
{
	int		size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		lower;
	int		size;

	lower = 0;
	size = ft_getsize(tab);
	if (size < 2)
		return ;
	while (--size)
	{
		i = 0;
		lower = 0;
		while (++i <= size)
		{
			if (ft_strcmp(tab[lower], tab[i]) > 0)
				lower = i;
		}
		if (lower)
			ft_swap(tab, tab + lower);
		tab++;
	}
}
