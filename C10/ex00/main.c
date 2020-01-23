/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 02:44:46 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:31:40 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BSIZE 100

int		ft_putstrn(char *str, int n)
{
	while (n-- > 0)
		write(1, str++, 1);
	return (-1);
}

int		ft_putstrerror(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (-1);
}

int		ft_display(char *file)
{
	int				fd;
	int				end;
	char			buffer[BSIZE];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((end = read(fd, buffer, BSIZE)))
		ft_putstrn(buffer, end);
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (ft_putstrerror("File name missing.\n"));
	if (ac > 2)
		return (ft_putstrerror("Too many argument.\n"));
	if (!ft_display(av[1]))
		return (ft_putstrerror("Cannot read file.\n"));
	return (0);
}
