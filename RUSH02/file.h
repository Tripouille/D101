/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 11:50:19 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 12:12:15 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_openfile(char *file);
void	ft_closefile(int fd);

#endif
