/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 20:02:13 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 14:20:01 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i] && *to_find)
	{
		j = 0;
		while (to_find[j] && (str[i + j] == to_find[j]))
			j++;
		if (!to_find[j])
			return (str + i);
	}
	return (!*to_find ? str : 0);
}
