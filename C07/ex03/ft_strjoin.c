/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 12:31:14 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 14:27:55 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		bytes;
	int		i;
	int		j;

	bytes = 1;
	bytes += (size > 1 ? ft_strlen(sep) * (size - 1) : 0);
	i = 0;
	while (i < size)
		bytes += ft_strlen(strs[i++]);
	if (!(join = malloc(sizeof(*join) * bytes)))
		return (0);
	j = 0;
	while (size-- > 0)
	{
		while (**strs)
			join[j++] = *(*strs)++;
		strs++;
		i = 0;
		while (size && sep[i])
			join[j++] = sep[i++];
	}
	join[j] = 0;
	return (join);
}
