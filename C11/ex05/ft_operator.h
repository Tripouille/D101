/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operator.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 20:12:47 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 10:13:08 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_OPERATOR_H
# define FT_OPERATOR_H

typedef int			(*t_fop)(int, int);

typedef struct		s_operator
{
	char		symb;
	t_fop		op;
}					t_operator;

#endif
