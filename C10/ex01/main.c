/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 02:44:46 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:46:00 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#define BSIZE 100

int		ft_putstrerror(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (-1);
}

int		ft_putstrn(char *str, int n)
{
	while (n-- > 0)
		write(1, str++, 1);
	return (-1);
}

void	ft_error(char *exname, char *file, char *str)
{
	ft_putstrerror(exname);
	ft_putstrerror(": ");
	ft_putstrerror(file);
	ft_putstrerror(": ");
	ft_putstrerror(str);
	ft_putstrerror("\n");
}

int		ft_display(char *exname, char *file, char *buffer)
{
	int		fd;
	int		end;

	fd = open(file, O_RDONLY);
	if (errno)
		ft_error(exname, file, strerror(errno));
	if (fd < 0)
		return (0);
	while ((end = read(fd, buffer, BSIZE)))
		ft_putstrn(buffer, end);
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	char	buffer[BSIZE];
	int		end;
	int		i;

	if (ac == 1)
	{
		while ((end = read(0, buffer, BSIZE)))
			ft_putstrn(buffer, end);
		return (0);
	}
	i = 1;
	while (i < ac)
		ft_display((*av) + 2, av[i++], buffer);
	return (0);
}
