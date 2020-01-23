/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ten_queens_puzzle.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 02:16:52 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 07:08:39 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_is_safe(int board[10][10], int y, int x)
{
	int		i;

	i = 0;
	while (++i <= y)
	{
		if (board[y - i][x])
			return (0);
		if (x - i >= 0 && board[y - i][x - i])
			return (0);
		if (x + i < 10 && board[y - i][x + i])
			return (0);
	}
	return (1);
}

void		ft_print_board(int board[10][10])
{
	int		y;
	int		x;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
		{
			if (board[y][x])
				ft_putchar(x + '0');
		}
	}
	ft_putchar('\n');
}

int			ft_seek_spot(int board[10][10], int y, int x)
{
	int		found;

	found = 0;
	if (ft_is_safe(board, y, x))
	{
		board[y][x] = 1;
		if (y == 9 && ++found)
			ft_print_board(board);
		else
			found += ft_seek_spot(board, y + 1, 0);
		board[y][x] = 0;
	}
	if (x < 9)
		found += ft_seek_spot(board, y, x + 1);
	return (found);
}

int			ft_ten_queens_puzzle(void)
{
	int		board[10][10];
	int		y;
	int		x;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			board[y][x] = 0;
	}
	return (ft_seek_spot(board, 0, 0));
}
