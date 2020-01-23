/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 07:52:43 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 12:12:12 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_charislower(char c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

int		ft_charisupper(char c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

int		ft_charisnum(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && !(ft_charislower(str[i]) || ft_charisupper(str[i])
		|| ft_charisnum(str[i])))
			i++;
		if (str[i])
			ft_charislower(str[i]) ? str[i++] += 'A' - 'a' : i++;
		while (str[i] && (ft_charislower(str[i]) || ft_charisupper(str[i])
		|| ft_charisnum(str[i])))
			ft_charisupper(str[i]) ? str[i++] -= 'A' - 'a' : i++;
	}
	return (str);
}
