/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 12:01:43 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:22:08 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include <stdlib.h>
# include "ft_atol.h"
# include "file.h"
# include "dico.h"
# include "ft_str.h"
# include "ft_list.h"

int		ft_getnumber(int fd, char *buffer, long long *value, char tmp[1]);
int		ft_getwriting(int fd, char *buffer, char **writing, char tmp[1]);
int		ft_getline(int fd, char *buffer, struct s_list **begin_list);

#endif
