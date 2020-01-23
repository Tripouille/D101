/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_foreach.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:32:28 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 15:43:06 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	if (length-- > 0)
		(*f)(*tab);
	if (length > 0)
		ft_foreach(++tab, length, f);
}