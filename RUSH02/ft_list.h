/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 01:26:46 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:19:44 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# include "dico.h"

typedef struct				s_list
{
	struct s_list		*next;
	struct s_dico		*dico;
}							t_list;

t_list						*ft_create_elem(struct s_dico *dico);
void						ft_list_push_back(t_list **begin_list,
		struct s_dico *dico);
void						ft_list_purge(t_list **begin_list);
t_list						*ft_listfind(t_list *begin_list,
		long long *data_ref, int (*cmp)());

#endif
