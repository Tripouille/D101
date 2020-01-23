/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 16:48:06 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 11:06:25 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;

	size = 0;
	while (src[size])
		size++;
	dup = malloc(sizeof(*dup) * (size + 1));
	if (!dup)
		return (0);
	dup[size] = 0;
	while (size--)
		dup[size] = src[size];
	return (dup);
}
