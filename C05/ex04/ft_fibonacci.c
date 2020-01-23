/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fibonacci.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 16:22:49 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 01:31:05 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 2)
		return (index < 0 ? -1 : index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
