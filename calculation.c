/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:33:58 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:33:59 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_z(t_m *m, int i)
{
	while (++i < m->quantity)
		m->d[i].z_tr = m->d[i].z * m->increase_height;
}

void	make_the_angles(t_m *m)
{
	if (!(m->a = (double*)malloc(sizeof(double) * 4)))
		error(6);
	m->a[3] = 0;
	m->a[0] = 0.00555555555 * -3 * M_PI - m->turn_up + m->turn_down;
	m->a[1] = 0.00555555555 * 5 * M_PI - m->turn_right + m->turn_left;
	m->a[2] = 0.00555555555 * -20 * M_PI;
}

void	matrix_multiply(t_m *m, int i)
{
	double	a;
	double	b;
	double	c;
	double	x;

	a = m->a[0];
	b = m->a[1];
	c = m->a[2];
	while (++i < m->quantity)
	{
		x = m->d[i].x;
		m->d[i].x_tr = x * (cos(b + c) + cos(b - c)) * 0.5 + m->d[i].y *
			(-cos(a + b + c) + cos(a - b + c) - cos(a + b - c) +
			cos(a - b - c) + 2 * sin(a + c) - 2 * sin(a - c)) *
			0.25 + m->d[i].z_tr * (-2 * cos(a + c) + 2 * cos(a - c) -
			sin(a + b + c) - sin(-a + b + c) - sin(a + b - c) -
			sin(-a + b - c)) * 0.25;
		m->d[i].y_tr = x * (-sin(b + c) + sin(b - c)) * 0.5 + m->d[i].y *
			(2 * cos(a + c) + 2 * cos(a - c) + sin(a + b + c) -
			sin(-a + b + c) - sin(a - b + c) - sin(a + b - c)) * 0.25 +
			m->d[i].z_tr * (-cos(a + b + c) - cos(-a + b + c) +
			cos(a - b + c) + cos(a + b - c) + 2 * sin(a + c) +
			2 * sin(a - c)) * 0.25;
	}
}

void	window_and_scale_calculation(t_m *m)
{
	m->scale = 1;
	m->w_h = m->height * m->scale * 2;
	m->w_w = m->width * m->scale * 2;
	while (m->w_h < 1000 && m->w_w < 1000)
	{
		m->w_h = m->height * ++m->scale * 2;
		m->w_w = m->width * m->scale * 2;
	}
}
