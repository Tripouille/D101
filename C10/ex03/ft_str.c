/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 11:48:28 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 11:56:37 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_str.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		n;

	n = 16;
	while (--n && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_bcopy(char buffer[16], char src[16])
{
	int		i;

	i = -1;
	while (++i < 16)
		buffer[i] = src[i];
}

void	ft_strerror(char *str)
{
	while (*str)
		write(2, str++, 1);
}
