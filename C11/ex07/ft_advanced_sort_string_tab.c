/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_advanced_sort_string_tab.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 00:03:20 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 14:43:52 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				i = 0;
			}
			j++;
		}
		i++;
	}
}
