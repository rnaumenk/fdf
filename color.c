/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:36:00 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:36:01 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		brightness(int color, double br)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16 & 0xFF) * br;
	green = (color >> 8 & 0xFF) * br;
	blue = (color & 0xFF) * br;
	color = (red << 16 | green << 8 | blue);
	return (color);
}

int				color_calc(t_m *m, int i, int next, double br)
{
	if (ft_abs(m->d[i].z) >= ft_abs(m->d[i + next].z))
		return (brightness(m->d[i].color, br));
	return (brightness(m->d[i + next].color, br));
}

void			change_drawcolor(t_m *m)
{
	if (m->color_r == 1)
		m->red = 255;
	else
		m->red = 0;
	if (m->color_g == 1)
		m->green = 255;
	else
		m->green = 0;
	if (m->color_b == 1)
		m->blue = 255;
	else
		m->blue = 0;
	m->color = (m->red << 16 | m->green << 8 | m->blue);
	if (m->color == 0)
		m->color = 16777215;
}
