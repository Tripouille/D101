/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_elem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 01:29:10 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:07:28 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(struct s_dico *dico)
{
	t_list		*elem;

	if (!(elem = malloc(sizeof(*elem))))
		return (0);
	elem->dico = dico;
	elem->next = 0;
	return (elem);
}

void		ft_list_push_back(t_list **begin_list, struct s_dico *dico)
{
	if (*begin_list)
		ft_list_push_back(&((*begin_list)->next), dico);
	else
		*begin_list = ft_create_elem(dico);
}

void		ft_list_purge(t_list **begin_list)
{
	if (begin_list && *begin_list && (*begin_list)->next)
		ft_list_purge(&((*begin_list)->next));
	if (begin_list && *begin_list)
	{
		free((*begin_list)->dico->writing);
		free((*begin_list)->dico);
		free(*begin_list);
		*begin_list = 0;
	}
}

t_list		*ft_listfind(t_list *begin_list, long long *data_ref,
		int (*cmp)())
{
	if (begin_list && !(*cmp)(begin_list->dico->value, *data_ref))
		return (begin_list);
	else if (begin_list && begin_list->next)
		return (ft_listfind(begin_list->next, data_ref, cmp));
	return (0);
}
