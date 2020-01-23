/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 17:41:38 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 20:23:31 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_valid_datas(char *data)
{
	int		one;
	int		two;
	int		three;
	int		four;

	one = 0;
	two = 0;
	three = 0;
	four = 0;
	while (*data)
	{
		if (*data == '1')
			one++;
		else if (*data == '2')
			two++;
		else if (*data == '3')
			three++;
		else if (*data == '4')
			four++;
		data++;
	}
	return (one < 2 || one > 4 || two > 12 || three > 12 || four > 4 ? 0 : 1);
}

void		ft_case4(char **board, int y, int x, char dir)
{
	int		i;

	i = -1;
	while (dir == 'd' && ++i < 4)
		board[i][x] = i + 1 + '0';
	while (dir == 'u' && ++i < 4)
		board[y - i][x] = i + 1 + '0';
	while (dir == 'r' && ++i < 4)
		board[y][i] = i + 1 + '0';
	while (dir == 'l' && ++i < 4)
		board[y][x - i] = i + 1 + '0';
}

int			ft_checkcase4(char **board, int y, int x, char dir)
{
	int		i;

	i = -1;
	while (dir == 'd' && ++i < 4)
	{
		if (!(board[i][x] == i + 1 + '0' || board[i][x] == '0'))
			return (0);
	}
	while (dir == 'u' && ++i < 4)
	{
		if (!(board[y - i][x] == i + 1 + '0' || board[y - i][x] == '0'))
			return (0);
	}
	while (dir == 'r' && ++i < 4)
	{
		if (!(board[y][i] == i + 1 + '0' || board[y][i] == '0'))
			return (0);
	}
	while (dir == 'l' && ++i < 4)
	{
		if (!(board[y][x - i] == i + 1 + '0' || board[y][x - i] == '0'))
			return (0);
	}
	return (1);
}
