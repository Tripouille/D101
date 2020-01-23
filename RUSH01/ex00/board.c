/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   board.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 11:19:39 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 20:05:36 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			ft_sqrt(int nb);

char		**ft_getboard(int size, char symb)
{
	char	**board;
	int		y;
	int		x;

	if (!(board = malloc(sizeof(*board) * size)))
		return (0);
	y = -1;
	while (++y < size)
	{
		if (!(board[y] = malloc(sizeof(**board) * size)))
			return (0);
		x = -1;
		while (++x < size)
			board[y][x] = symb;
	}
	return (board);
}

void		ft_showboard(char **board, int size)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			write(1, board[y] + x, 1);
			if (x + 1 < size)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int			ft_boardsize(char *data)
{
	int		size;

	size = 0;
	while (*data)
	{
		if (*data && (*data >= '1' && *data <= '9'))
		{
			size++;
			data++;
		}
		else
			return (0);
		if ((*data && *data != ' ') || (*data == ' ' && !data[1]))
			return (0);
		else if (*data)
			data++;
	}
	return (ft_sqrt(size));
}

int			ft_view(char **board, int size, int pos[2], char direction)
{
	int		i;
	int		count;
	int		highest;

	i = -1;
	count = 1;
	highest = board[pos[0]][pos[1]];
	while (++i < size - 1)
	{
		if (direction == 'u')
			pos[0]--;
		else if (direction == 'd')
			pos[0]++;
		else if (direction == 'r')
			pos[1]++;
		else if (direction == 'l')
			pos[1]--;
		if (board[pos[0]][pos[1]] > highest)
		{
			highest = board[pos[0]][pos[1]];
			count++;
		}
	}
	return (count);
}

void		ft_fillview(char **view_board, int size, char *data)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			view_board[y][x] = *data;
			data += 2;
		}
	}
}
