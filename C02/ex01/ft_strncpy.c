/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/05 12:40:42 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 12:40:45 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
