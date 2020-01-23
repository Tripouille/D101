/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 18:49:07 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 19:19:27 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	while (*src && nb-- > 0)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}
