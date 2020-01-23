/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 18:26:02 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 15:14:56 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

int		print_error(int id)
{
	if (id == 1)
		ft_putstr("Incorrect usage: Use ./a.out \"Number 1\" \"Number 2\"!\n");
	else if (id == 2)
		ft_putstr("Incorrect value: Arg is not a number!\n");
	else if (id == 3)
		ft_putstr("Incorrect value: Number is not positif!\n");
	else if (id == 4)
		ft_putstr("Incorrect value: Max value is 2147483647!\n");
	else if (id == 5)
		ft_putstr("Incorrect value: 0 Is not allowed!\n");
	else
		ft_putstr("ERROR!\n");
	return (-1);
}

char	*ft_clean(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int		ft_atoiv(char *str, int *errid)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	str = ft_clean(str);
	if (str[i] == '-')
	{
		*errid = 3;
		return (0);
	}
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		*errid = 2;
	while (nb < 2147483648 && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	if (str[i - 1] >= '0' && str[i - 1] <= '9' && nb > 2147483647)
		*errid = 4;
	return (nb);
}

void	print_line(int x, int y, int line, int col)
{
	if (line == 0)
	{
		if (col == 0 || col == (x - 1))
			ft_putchar((col == 0) ? '/' : '\\');
		else
			ft_putchar('*');
	}
	else if (line == y - 1)
	{
		if (col == 0 || col == (x - 1))
			ft_putchar((col == 0) ? '\\' : '/');
		else
			ft_putchar('*');
	}
}

void	rush(int x, int y)
{
	int line;
	int col;

	line = 0;
	while (line < y)
	{
		col = 0;
		while (col < x)
		{
			if (line == 0 || line == (y - 1))
				print_line(x, y, line, col);
			else if (!(col == 0 || col == (x - 1)))
				ft_putchar(' ');
			else if (col == 0 || col == (x - 1))
				ft_putchar('*');
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
