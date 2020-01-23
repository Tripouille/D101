/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 11:47:24 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 12:12:19 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "file.h"

int		ft_openfile(char *file)
{
	return (open(file, O_RDONLY));
}

void	ft_closefile(int fd)
{
	close(fd);
}
