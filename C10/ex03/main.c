/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_memory.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 22:10:24 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 11:59:58 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ft_print.h"
#include "ft_str.h"

void	ft_error(char *exname, char *file, char *error)
{
	ft_strerror(exname);
	ft_strerror(": ");
	ft_strerror(file);
	ft_strerror(": ");
	ft_strerror(error);
	ft_strerror("\n");
}

void	ft_bdf(char *exname, char *file)
{
	ft_strerror(exname);
	ft_strerror(": ");
	ft_strerror(file);
	ft_strerror(": ");
	ft_strerror("Bad file descriptor\n");
}

void	ft_last(int offset, int option)
{
	if (offset)
	{
		ft_printoffset(offset, option);
		ft_putchar('\n');
	}
}

void	ft_hexdump(int fd, int option, int *succes)
{
	char			buffer[16];
	char			buffer2[16];
	int				offset;
	int				n;
	int				star;

	*succes = 1;
	offset = 0;
	while ((n = read(fd, buffer, 16)))
	{
		if (ft_strcmp(buffer, buffer2))
		{
			star = 0;
			ft_printoffset(offset, option);
			ft_printhexa(buffer, n, option);
			if (option)
				ft_putstrn(buffer, n);
			ft_putchar('\n');
		}
		else if (!star && ++star)
			write(1, "*\n", 2);
		offset += n;
		ft_bcopy(buffer2, buffer);
	}
	ft_last(offset, option);
}

int		main(int ac, char **av)
{
	int		i;
	int		option;
	int		fd;
	int		succes;

	option = 0;
	succes = 0;
	if (ac > 1)
		option = (av[1][0] == '-' && av[1][1] == 'C' ? 1 : 0);
	if (ac < 2 + option)
		ft_hexdump(0, option, &succes);
	i = option;
	while (++i < ac)
	{
		errno = 0;
		fd = open(av[i], O_RDONLY);
		if (errno)
			ft_error((*av) + 2, av[i], strerror(errno));
		if (!errno)
			ft_hexdump(fd, option, &succes);
		close(fd);
	}
	if (!succes && ac >= 2 + option)
		ft_bdf((*av) + 2, av[i - 1]);
	return (0);
}
