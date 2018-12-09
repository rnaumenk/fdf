/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:48:39 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:48:40 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		win_exit(t_m *m)
{
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
	return (0);
}

void	free_split(char ***temp)
{
	int		i;
	char	**split;

	split = *temp;
	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
	split = NULL;
}
