/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 19:09:32 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 00:53:48 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_str.h"

void	ft_putstrn(char *str, int n)
{
	while (n-- > 0)
		write(1, str++, 1);
}

void	ft_putstrerror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_error(char *exname, char *file, char *error)
{
	ft_putstrerror(exname);
	ft_putstrerror(": ");
	ft_putstrerror(file);
	ft_putstrerror(": ");
	ft_putstrerror(error);
	ft_putstrerror("\n");
}

int		ft_noargument(char *exname)
{
	ft_putstrerror(exname);
	ft_putstrerror(": ");
	ft_putstrerror("option requires an argument -- c\n");
	ft_putstrerror("usage: ");
	ft_putstrerror(exname);
	ft_putstrerror(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n");
	return (-1);
}
