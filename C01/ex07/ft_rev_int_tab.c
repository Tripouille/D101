/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rev_int_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 07:57:37 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 09:22:59 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		mid;

	mid = (size / 2);
	while (mid--)
		ft_swap(tab + mid, tab + ((size - 1) - mid));
}
