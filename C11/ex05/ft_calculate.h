/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calculate.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 20:56:02 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 10:16:56 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_CALCULATE_H
# define FT_CALCULATE_H
# include "ft_operator.h"

int			ft_calculate(int a, int b, char op, struct s_operator *optab);
void		ft_calcinit(struct s_operator *calc);

#endif
