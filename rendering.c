/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:41:38 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:41:39 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		x_longer(t_m *m, int i, int next)
{
	double	x;
	double	y;
	double	k;
	double	dx;
	double	dy;

	y = m->d[i].win_y;
	x = m->d[i].win_x;
	dx = m->d[i + next].win_x - m->d[i].win_x;
	dy = m->d[i + next].win_y - m->d[i].win_y;
	k = dy / ft_abs(dx);
	m->next = next;
	if (dx > 0)
	{
		while (++x < m->d[i + next].win_x)
			wu_shit_for_x_longer(m, i, y += k, x);
	}
	else
	{
		while (--x > m->d[i + next].win_x)
			wu_shit_for_x_longer(m, i, y += k, x);
	}
}

static void		y_longer(t_m *m, int i, int next)
{
	double	x;
	double	y;
	double	k;
	double	dx;
	double	dy;

	y = m->d[i].win_y;
	x = m->d[i].win_x;
	dx = m->d[i + next].win_x - m->d[i].win_x;
	dy = m->d[i + next].win_y - m->d[i].win_y;
	k = dx / ft_abs(dy);
	m->next = next;
	if (dy > 0)
	{
		while (++y < m->d[i + next].win_y)
			wu_shit_for_y_longer(m, i, x += k, y);
	}
	else
	{
		while (--y > m->d[i + next].win_y)
			wu_shit_for_y_longer(m, i, x += k, y);
	}
}

void			draw_line_x(t_m *m, int i)
{
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = m->d[i + 1].win_x - m->d[i].win_x;
	dy = m->d[i + 1].win_y - m->d[i].win_y;
	y = m->d[i].win_y;
	x = m->d[i].win_x;
	if (!dx)
		vertical_line(m, m->d[i].win_y, i, 1);
	else if (!dy)
		horizontal_line(m, m->d[i].win_x, i, 1);
	else
	{
		if (ft_abs(dx) >= ft_abs(dy))
			x_longer(m, i, 1);
		else
			y_longer(m, i, 1);
	}
}

void			draw_line_y(t_m *m, int i)
{
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = m->d[i + m->width].win_x - m->d[i].win_x;
	dy = m->d[i + m->width].win_y - m->d[i].win_y;
	y = m->d[i].win_y;
	x = m->d[i].win_x;
	if (!dx)
		vertical_line(m, m->d[i].win_y, i, m->width);
	else if (!dy)
		horizontal_line(m, m->d[i].win_x, i, m->width);
	else
	{
		if (ft_abs(dx) >= ft_abs(dy))
			x_longer(m, i, m->width);
		else
			y_longer(m, i, m->width);
	}
}
