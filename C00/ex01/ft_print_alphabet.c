/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_alphabet.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jgambard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 13:52:34 by jgambard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 14:26:24 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a' - 1;
	while (++letter <= 'z')
		write(1, &letter, 1);
}
