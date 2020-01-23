/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boolean.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 04:13:21 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 04:45:00 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN(nbr) !(nbr % 2)
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# include <unistd.h>

typedef char	t_bool;

#endif
