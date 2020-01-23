/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 19:10:40 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 20:46:31 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_cinstr(char c, char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] && c != str[pos])
		pos++;
	return (c == str[pos] ? pos : -1);
}

int		ft_base_is_valid(char *base)
{
	int		len;

	if (!base)
		return (0);
	len = -1;
	while (base[++len])
	{
		if (ft_cinstr(base[len], base + len + 1) >= 0)
			return (0);
		if (base[len] == '-' || base[len] == '+' ||
				(base[len] >= 9 && base[len] <= 13) || base[len] == ' ')
			return (0);
	}
	return (len);
}

char	ft_strisvalid(char *str, char *base)
{
	int		i;

	i = 0;
	while (str[i] && (ft_cinstr(str[i], base) >= 0))
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		minus;
	int		base_size;
	int		limit;

	if (!str || !base)
		return (0);
	result = 0;
	minus = 0;
	base_size = ft_base_is_valid(base);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		minus += (*str++ == '-' ? 1 : 0);
	limit = ft_strisvalid(str, base);
	if (base_size < 2 || !limit)
		return (0);
	while (*str && limit--)
		result = (result * base_size) + (ft_cinstr(*str++, base));
	return (result * (minus % 2 ? -1 : 1));
}
