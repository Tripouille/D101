/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 10:30:58 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 20:11:05 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char		**ft_getboard(int size, char symb);
int			ft_boardsize(char *data);
void		ft_fillview(char **view_board, int size, char *data);
int			ft_resolve(char **board, char **view_board, int size);
int			ft_precheck(char **board, char **view_board, int size);
int			ft_valid_datas(char *data);

int			ft_missingn(char **board, int y, int x)
{
	int		result;

	result = 0;
	while (y < 4)
		result += board[y++][x] - '0';
	return (10 - result);
}

void		ft_lastcheck(char **board, int size)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (board[y][x] == '0')
			{
				board[y][x] = ft_missingn(board, 0, x) + '0';
				return ;
			}
		}
	}
}

int			ft_checkdata(char *data, int size)
{
	while (*data && (*data <= size + '0' || *data == ' '))
		data++;
	return (*data ? 0 : 1);
}

int			ft_printerror(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int			main(int argc, char **argv)
{
	char	**board;
	char	**view_board;
	int		size;

	if (argc != 2)
		return (ft_printerror());
	size = ft_boardsize(argv[1]);
	if (size != 4)
		return (ft_printerror());
	if (!ft_checkdata(argv[1], size))
		return (ft_printerror());
	if (!ft_valid_datas(argv[1]))
		return (ft_printerror());
	board = ft_getboard(size, '0');
	view_board = ft_getboard(size, '0');
	ft_fillview(view_board, size, argv[1]);
	if (!ft_precheck(board, view_board, size))
		return (ft_printerror());
	if (!ft_resolve(board, view_board, size))
		return (ft_printerror());
	free(board);
	free(view_board);
	return (0);
}
