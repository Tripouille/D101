/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 19:10:07 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 00:53:25 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

void	ft_putstrn(char *str, int n);
void	ft_putstrerror(char *str);
void	ft_putstr(char *str);
void	ft_error(char *exname, char *file, char *error);
int		ft_noargument(char *exname);

#endif
