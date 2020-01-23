/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 16:40:43 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 02:41:14 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_as(int *tab, int length, int (*f)(int, int))
{
	if (length > 1 && (*f)(*tab, *(tab + 1)) > 0)
		return (0);
	else if (length > 1 && (*f)(*tab, *(tab + 1)) <= 0)
		return (ft_is_as(++tab, --length, f));
	return (1);
}

int		ft_is_ds(int *tab, int length, int (*f)(int, int))
{
	if (length > 1 && (*f)(*tab, *(tab + 1)) < 0)
		return (0);
	else if (length > 1 && (*f)(*tab, *(tab + 1)) >= 0)
		return (ft_is_ds(++tab, --length, f));
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (ft_is_ds(tab, length, f) || ft_is_as(tab, length, f) ? 1 : 0);
}
