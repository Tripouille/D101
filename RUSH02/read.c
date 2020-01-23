/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 11:47:15 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:43:07 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "read.h"

int		ft_getnumber(int fd, char *buffer, long long *value, char tmp[1])
{
	int		cursor;

	cursor = 0;
	if (*tmp >= '0' && *tmp <= '9')
		buffer[cursor++] = *tmp;
	while (read(fd, tmp, 1) && (*tmp >= '0' && *tmp <= '9'))
		buffer[cursor++] = *tmp;
	buffer[cursor] = 0;
	*value = ft_atol(buffer);
	return (cursor);
}

int		ft_getwriting(int fd, char *buffer, char **writing, char tmp[1])
{
	int		cursor;
	int		rsize;

	while (*tmp != ':' && read(fd, tmp, 1) && *tmp == ' ')
		;
	if (*tmp != ':')
		return (0);
	while (read(fd, tmp, 1) && *tmp == ' ')
		;
	if (!*tmp || *tmp == '\n')
		return (0);
	cursor = 0;
	buffer[cursor++] = *tmp;
	while (read(fd, tmp, 1) && *tmp != '\n')
		buffer[cursor++] = *tmp;
	buffer[cursor] = 0;
	rsize = ft_strlen(buffer);
	if (!((*writing) = malloc(sizeof(**writing) * (rsize + 1))))
		return (0);
	ft_strcpy(*writing, buffer);
	return (1);
}

int		ft_getline(int fd, char *buffer, struct s_list **begin_list)
{
	t_dico		*dico;
	char		tmp[1];

	*tmp = 0;
	if (!read(fd, tmp, 1))
		return (2);
	if (*tmp == '\n')
		return (1);
	if (!(dico = malloc(sizeof(*dico))))
		return (0);
	if (!(ft_getnumber(fd, buffer, &(dico->value), tmp)))
	{
		free(dico);
		ft_list_purge(begin_list);
		return (0);
	}
	if (!(ft_getwriting(fd, buffer, &(dico->writing), tmp)))
	{
		free(dico);
		ft_list_purge(begin_list);
		return (0);
	}
	ft_list_push_back(begin_list, dico);
	return (1);
}
