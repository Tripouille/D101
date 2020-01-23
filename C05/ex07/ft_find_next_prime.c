/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_next_prime.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 19:02:55 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 06:03:09 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	unsigned long		divisor;
	unsigned long		lnb;

	lnb = nb;
	if (lnb <= 1 || (!(lnb % 2) && lnb != 2))
		return (0);
	divisor = 3;
	while ((lnb % divisor) && divisor * divisor > 0 && divisor * divisor <= lnb)
		divisor += 2;
	return ((lnb % divisor || lnb == 3) ? 1 : 0);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	return (ft_is_prime(nb) ? nb : ft_find_next_prime(nb + 1));
}
