/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 12:28:14 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 15:05:58 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstrcr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	if ((*s1 || *s2) && (*s1 == *s2))
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_asciisort(int size, char **tab)
{
	int		i;
	int		lower;
	char	*tmp;

	lower = 0;
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
		{
			tmp = *tab;
			*tab = tab[lower];
			tab[lower] = tmp;
		}
		tab++;
	}
}

int		main(int argc, char **argv)
{
	ft_asciisort(--argc, ++argv);
	while (argc--)
		ft_putstrcr(*argv++);
	return (0);
}
