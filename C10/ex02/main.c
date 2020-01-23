/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:10:22 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 00:49:13 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_atol.h"
#include "ft_str.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int		ft_badc(char *exname, char *c)
{
	ft_putstr(exname);
	ft_putstr(": illegal offset -- ");
	ft_putstr(c);
	ft_putstr("\n");
	return (-1);
}

void	ft_tail(int fd, long c)
{
	int		i;
	int		r;
	char	b1[c];
	char	b2[c];

	i = 0;
	while ((r = (read(fd, (i++ % 2 ? b2 : b1), c))) == c)
		;
	if (i > 1)
	{
		if (i % 2)
		{
			ft_putstrn(b2 + r, c - r);
			ft_putstrn(b1, r);
		}
		else
		{
			ft_putstrn(b1 + r, c - r);
			ft_putstrn(b2, r);
		}
	}
	else
		ft_putstrn(b1, r);
}

void	ft_header(char *file)
{
	ft_putstr("==> ");
	ft_putstr(file);
	ft_putstr(" <==\n");
}

void	ft_manage(int ac, char **av, int c)
{
	int		fd;
	int		i;
	int		perrno;

	i = 2;
	while (++i < ac)
	{
		errno = 0;
		fd = open(av[i], O_RDONLY);
		if (i < ac && i != 3 && !errno)
			ft_putstr("\n");
		if (errno)
			ft_error((*av) + 2, av[i], strerror(errno));
		if (ac > 4 && !errno)
			ft_header(av[i]);
		if (!errno)
			ft_tail(fd, c);
		close(fd);
		perrno = errno;
	}
}

int		main(int ac, char **av)
{
	long	c;

	if (ac < 2)
		return (-1);
	if (ac == 2)
		return (ft_noargument((*av) + 2));
	c = ft_atol(av[2]);
	if (c < 0)
		return (ft_badc((*av) + 2, av[2]));
	if (ac == 3)
		ft_tail(0, c);
	else
		ft_manage(ac, av, c);
	return (0);
}
