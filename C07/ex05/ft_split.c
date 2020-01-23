/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 16:09:13 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 02:45:54 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_cinstr(char c, char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] && str[pos] != c)
		pos++;
	return (str[pos] == c ? pos : -1);
}

int		ft_wc(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_cinstr(str[i], charset) >= 0)
			i++;
		count += (str[i] ? 1 : 0);
		while (str[i] && ft_cinstr(str[i], charset) < 0)
			i++;
	}
	return (count);
}

int		ft_wsize(char *str, char *charset)
{
	int		i;

	i = 0;
	while (str[i] && ft_cinstr(str[i], charset) < 0)
		i++;
	return (i);
}

void	ft_fillsplit(char **split, char *str, char *charset, int w)
{
	int		wsize;
	int		istr;
	int		i;
	int		j;

	istr = 0;
	i = -1;
	while (++i < w)
	{
		while (str[istr] && ft_cinstr(str[istr], charset) >= 0)
			istr++;
		wsize = ft_wsize(str + istr, charset);
		split[i] = malloc(sizeof(**split) * (1 + wsize));
		split[i][wsize] = 0;
		j = 0;
		while (str[istr + j] && ft_cinstr(str[istr + j], charset) < 0)
		{
			split[i][j] = str[istr + j];
			j++;
		}
		istr += j;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		w;

	if (!str || !charset)
		return (0);
	w = ft_wc(str, charset);
	if (!(split = malloc(sizeof(*split) * (1 + w))))
		return (0);
	if (w)
		ft_fillsplit(split, str, charset, w);
	split[w] = 0;
	return (split);
}
