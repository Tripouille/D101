/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:15:21 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 00:56:23 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_atol.h"

char		*ft_remove_front_space(char *str)
{
	while (str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	return (str);
}

int			ft_isnum(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

long		ft_atol(char *str)
{
	long		result;

	result = 0;
	str = ft_remove_front_space(str);
	if (*str == '-' || *str == '+')
		result += *str++ == '+' ? -1 : 0;
	while (result >= 0 && ft_isnum(*str))
		result = (result * 10) + (*str++ - '0');
	return (*str ? -1 : result);
}
