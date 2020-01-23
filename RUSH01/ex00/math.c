/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   math.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 12:12:02 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 16:27:49 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		sqrt;

	sqrt = 2;
	if (nb == 1)
		return (1);
	while (nb > 0 && (sqrt * sqrt) > 0 && (sqrt * sqrt) < nb)
		sqrt++;
	return ((nb > 0 && sqrt * sqrt == nb) ? sqrt : 0);
}