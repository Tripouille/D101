/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   board2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 05:31:09 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 16:18:37 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void		ft_nslot(char **mask, int size, int *y, int *x)
{
	while (mask[*y][*x] != '0')
	{
		(*x)--;
		if (*x < 0)
		{
			*x = size - 1;
			(*y)--;
		}
	}
}

void		ft_next(char **board, int size, char **mask)
{
	int		y;
	int		x;

	y = size - 1;
	x = size - 1;
	ft_nslot(mask, size, &y, &x);
	board[y][x]++;
	while (board[y][x] > size + '0' && board[0][0] != size + 1 + '0')
	{
		board[y][x] = '1';
		x--;
		if (x < 0)
		{
			x = size - 1;
			y--;
		}
		ft_nslot(mask, size, &y, &x);
		board[y][x]++;
	}
}

int			ft_hlinevalid(char **board, int size)
{
	int		y;
	int		x;
	int		j;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			j = x;
			while (++j < size)
			{
				if (board[y][x] == board[y][j])
					return (0);
			}
		}
	}
	return (1);
}

int			ft_vlinevalid(char **board, int size)
{
	int		y;
	int		x;
	int		j;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			j = y;
			while (++j < size)
			{
				if (board[y][x] == board[j][x])
					return (0);
			}
		}
	}
	return (1);
}
