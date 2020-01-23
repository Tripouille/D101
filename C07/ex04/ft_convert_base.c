/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 14:37:57 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 16:06:06 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c);
int		ft_cinstr(char c, char *str);
int		ft_base_is_valid(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_pow(int number, int power)
{
	int		result;

	result = 1;
	while (power-- > 0)
		result *= number;
	return (result);
}

int		ft_getdiv(int val, int bsize)
{
	int		div;

	div = 1;
	while ((val / bsize) / div)
		div *= bsize;
	return (div);
}

char	*ft_nbto_base(long val, char *base_to, int i)
{
	char	*result;
	int		bsize;
	int		power;
	int		div;

	bsize = ft_strlen(base_to);
	power = 0;
	while ((val / bsize) / ft_pow(bsize, power))
		power++;
	if (!(result = malloc(sizeof(*result) * ((val < 0 ? 1 : 0) + power + 2))))
		return (0);
	if (val < 0)
		result[i++] = '-';
	val *= (val < 0 ? -1 : 1);
	div = ft_pow(bsize, power);
	while (div)
	{
		result[i++] = base_to[val / div];
		val %= div;
		div /= bsize;
	}
	result[i] = 0;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	val;

	if (ft_base_is_valid(base_to) < 2 || ft_base_is_valid(base_from) < 2)
		return (0);
	val = ft_atoi_base(nbr, base_from);
	return (ft_nbto_base(val, base_to, 0));
}
