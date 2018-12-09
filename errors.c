/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:32:03 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:32:04 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int nb)
{
	if (nb == 1)
		write(1, "Too few dots\n", 13);
	else if (nb == 2)
		write(1, "Lines are of the different length\n", 34);
	else if (nb == 3)
		write(1, "usage: ./fdf source_file\n", 25);
	else if (nb == 4)
		write(1, "File opening has been failed\n", 29);
	else if (nb == 5)
		write(1, "File is empty or path given is wrong\n", 37);
	else if (nb == 6)
		write(1, "Memory allocation error\n", 24);
	exit(0);
}
