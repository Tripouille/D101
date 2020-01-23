/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 13:33:13 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 12:55:43 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int					ft_isnum(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

long long			ft_atol(char *str)
{
	long long		result;

	result = 0;
	if (*str == '+')
		str++;
	while (ft_isnum(*str) && result < 999999999999)
		result = (result * 10) + (*str++ - '0');
	if (result > 999999999999)
		return (-1);
	return (result);
}
