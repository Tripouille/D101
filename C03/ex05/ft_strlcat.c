/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 20:45:16 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 01:56:45 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dl;
	unsigned int		sl;

	dl = 0;
	while (dest[dl])
		dl++;
	sl = 0;
	while (size > 1 && src[sl] && (dl + sl < size - 1))
	{
		dest[dl + sl] = src[sl];
		sl++;
	}
	if (dl < size - 1)
		dest[dl + sl] = 0;
	if (size && dl > size)
		dl = size;
	while (src[sl])
		sl++;
	return (size ? sl + dl : sl);
}
