/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 05:27:01 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 20:10:11 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_getboard(int size, char symb);
int			ft_precheck(char **board, char **view_board, int size);
void		ft_next(char **board, int size, char **mask);
int			ft_vlinevalid(char **board, int size);
int			ft_hlinevalid(char **board, int size);
void		ft_showboard(char **board, int size);
int			ft_view(char **board, int size, int pos[2], char direction);
void		ft_lastcheck(char **board, int size);

int			ft_ctop(char **board, char *top, int size)
{
	int		pos[2];

	pos[1] = 0;
	while (pos[1] < size)
	{
		pos[0] = 0;
		if (ft_view(board, size, pos, 'd') != top[pos[1]] - '0')
			return (0);
		pos[1]++;
	}
	return (1);
}

int			ft_cbot(char **board, char *bot, int size)
{
	int		pos[2];

	pos[1] = 0;
	while (pos[1] < size)
	{
		pos[0] = size - 1;
		if (ft_view(board, size, pos, 'u') != bot[pos[1]] - '0')
			return (0);
		pos[1]++;
	}
	return (1);
}

int			ft_cleft(char **board, char *left, int size)
{
	int		pos[2];

	pos[0] = 0;
	while (pos[0] < size)
	{
		pos[1] = 0;
		if (ft_view(board, size, pos, 'r') != left[pos[0]] - '0')
			return (0);
		pos[0]++;
	}
	return (1);
}

int			ft_cright(char **board, char *right, int size)
{
	int		pos[2];

	pos[0] = 0;
	while (pos[0] < size)
	{
		pos[1] = size - 1;
		if (ft_view(board, size, pos, 'l') != right[pos[0]] - '0')
			return (0);
		pos[0]++;
	}
	return (1);
}

int			ft_resolve(char **board, char **view_board, int size)
{
	char **mask;

	mask = ft_getboard(size, '0');
	ft_precheck(mask, view_board, size);
	mask[0][0] = '0';
	while (board[0][0] <= size + '0')
	{
		if (ft_vlinevalid(board, size)
		&& ft_hlinevalid(board, size)
		&& ft_ctop(board, view_board[0], size)
		&& ft_cbot(board, view_board[1], size)
		&& ft_cleft(board, view_board[2], size)
		&& ft_cright(board, view_board[3], size))
		{
			ft_lastcheck(board, size);
			ft_showboard(board, size);
			free(mask);
			return (1);
		}
		else
			ft_next(board, size, mask);
	}
	free(mask);
	return (0);
}
