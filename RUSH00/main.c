/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 11:38:09 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 19:22:51 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_atoiv(const char *str, int *errid);
void	rush(int x, int y);
int		print_error(int id);

int		main(int ac, char **av)
{
	int		number1;
	int		number2;
	int		errid;

	errid = 0;
	if (ac != 3)
		return (print_error(1));
	number1 = ft_atoiv(av[1], &errid);
	if (errid)
		return (print_error(errid));
	else if (number1 == 0)
		return (print_error(5));
	number2 = ft_atoiv(av[2], &errid);
	if (errid)
		return (print_error(errid));
	else if (number2 == 0)
		return (print_error(5));
	if (!errid)
		rush(number1, number2);
	return (0);
}
