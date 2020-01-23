/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   precheck.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 12:58:27 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 17:36:36 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_checkcase4(char **board, int y, int x, char dir);
void		ft_case4(char **board, int y, int x, char dir);

void		ft_prechecktop(char **board, char *top, int size)
{
	int		x;

	x = -1;
	while (++x < size)
	{
		if (top[x] == '1')
			board[0][x] = '4';
		else if (top[x] == '4')
			ft_case4(board, 0, x, 'd');
	}
}

int			ft_precheckbot(char **board, char *bot, int size)
{
	int		x;

	x = -1;
	while (++x < size)
	{
		if (bot[x] == '1')
		{
			if (board[size - 1][x] == '0' || board[size - 1][x] == '4')
				board[size - 1][x] = '4';
			else
				return (0);
		}
		else if (bot[x] == '4')
		{
			if (!ft_checkcase4(board, size - 1, x, 'u'))
				return (0);
			else
				ft_case4(board, size - 1, x, 'u');
		}
	}
	return (1);
}

int			ft_precheckleft(char **board, char *left, int size)
{
	int		y;

	y = -1;
	while (++y < size)
	{
		if (left[y] == '1')
		{
			if (board[y][0] == '0' || board[y][0] == '4')
				board[y][0] = '4';
			else
				return (0);
		}
		else if (left[y] == '4')
		{
			if (!ft_checkcase4(board, y, 0, 'r'))
				return (0);
			else
				ft_case4(board, y, 0, 'r');
		}
	}
	return (1);
}

int			ft_precheckright(char **board, char *right, int size)
{
	int		y;

	y = -1;
	while (++y < size)
	{
		if (right[y] == '1')
		{
			if (board[y][size - 1] == '0' || board[y][size - 1] == '4')
				board[y][size - 1] = '4';
			else
				return (0);
		}
		else if (right[y] == '4')
		{
			if (!ft_checkcase4(board, y, size - 1, 'l'))
				return (0);
			else
				ft_case4(board, y, size - 1, 'l');
		}
	}
	return (1);
}

int			ft_precheck(char **board, char **view_board, int size)
{
	ft_prechecktop(board, view_board[0], size);
	if (!(ft_precheckbot(board, view_board[1], size)))
		return (0);
	if (!(ft_precheckleft(board, view_board[2], size)))
		return (0);
	if (!(ft_precheckright(board, view_board[3], size)))
		return (0);
	return (1);
}
