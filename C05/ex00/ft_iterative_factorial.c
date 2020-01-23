/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_factorial.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 00:54:38 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 01:33:29 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		result;

	result = 1;
	while (nb > 1)
		result *= nb--;
	return (nb >= 0 ? result : 0);
}
