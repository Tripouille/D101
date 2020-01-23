/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 14:39:53 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 20:54:30 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_remove_front_space(char *str)
{
	while (str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	return (str);
}

int		ft_isnum(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int		ft_atoi(char *str)
{
	int		result;
	int		minus;

	result = 0;
	minus = 0;
	str = ft_remove_front_space(str);
	while (*str == '-' || *str == '+')
		minus += (*str++ == '-' ? 1 : 0);
	while (ft_isnum(*str))
		result = (result * 10) + (*str++ - '0');
	return (result * (minus % 2 ? -1 : 1));
}
