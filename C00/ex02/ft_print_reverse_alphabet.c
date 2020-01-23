/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_reverse_alphabet.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 14:33:22 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 14:40:29 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z' + 1;
	while (--letter >= 'a')
		write(1, &letter, 1);
}
