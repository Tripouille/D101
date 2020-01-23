/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 11:23:53 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:20:02 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "define.h"
#include "file.h"
#include "read.h"
#include "ft_put.h"
#include "ft_list.h"
#include "printer.h"

int		main(int ac, char **av)
{
	char				buffer[BSIZE];
	int					fd;
	t_list				*ldico;
	long long			nbr;

	ldico = 0;
	if (ac == 3 && (fd = ft_openfile(av[1])) < 0)
		return (ft_putstrerror("Error\n"));
	else if (ac == 2 && (fd = ft_openfile("numbers.dict")) < 0)
		return (ft_putstrerror("Error\n"));
	else if (ac == 1 || ac > 3)
		return (ft_putstrerror("Error\n"));
	while (ft_getline(fd, buffer, &ldico) == 1)
		;
	ft_closefile(fd);
	if (!ldico)
		return (ft_putstrerror("Dict Error\n"));
	if (!ft_checkdico(ldico))
		return (ft_error(ldico, "Dict Error\n"));
	if (!ft_isnumeric(av[ac - 1]))
		return (ft_error(ldico, "Error\n"));
	if ((nbr = ft_atol(av[ac - 1])) == -1)
		return (ft_error(ldico, "Error\n"));
	ft_printer(ldico, nbr);
	return (ft_succes(ldico));
}
