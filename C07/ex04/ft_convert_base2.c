/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 14:38:00 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/13 01:22:28 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int		ft_cinstr(char c, char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] && str[pos] != c)
		pos++;
	return (str[pos] == c ? pos : -1);
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
		if (base[len] == '-' || base[len] == '+' || ft_isspace(base[len]))
			return (0);
	}
	return (len);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		minus;
	int		base_size;

	if (!str || !base)
		return (0);
	result = 0;
	minus = 0;
	base_size = ft_base_is_valid(base);
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		minus += (*str++ == '-' ? 1 : 0);
	if (base_size < 2)
		return (0);
	while (*str && ft_cinstr(*str, base) >= 0)
		result = (result * base_size) + (ft_cinstr(*str++, base));
	return (result * (minus % 2 ? -1 : 1));
}
