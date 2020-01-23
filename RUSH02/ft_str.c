/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/05 08:20:12 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 15:02:07 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = *src;
	return (dest);
}

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
