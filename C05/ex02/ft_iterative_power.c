/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 14:03:55 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 14:22:17 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		result;

	result = 1;
	while (power > 0 && power--)
		result *= nb;
	return (power >= 0 ? result : 0);
}
