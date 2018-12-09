/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:37:12 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:37:13 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_off(int button, int x, int y, t_m *m)
{
	x = 0;
	y = 0;
	if (button == 1)
		m->mouse_on = 0;
	return (0);
}

int		mouse_move(int x, int y, t_m *m)
{
	if (m->mouse_on == 1 && x < m->w_w && x > 0 && y > 0 && y < m->w_h &&
		m->tab_on == 0)
	{
		m->right = x - m->mouse_x;
		m->down = y - m->mouse_y;
		mlx_shit(m);
	}
	if (m->mouse_on == 1 && x < m->w_w && x > 0 && y > 0 && y < m->w_h &&
		m->tab_on == 1)
		mlx_pixel_put(m->mlx, m->win, x, y, m->color);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_m *m)
{
	if (button == 4)
		m->scale++;
	if (button == 1)
	{
		m->mouse_x = x;
		m->mouse_y = y;
		m->mouse_on = 1;
	}
	if (button == 5 && m->scale - 1 > 0)
		m->scale--;
	if (button == 6 || button == 7)
	{
		m->increase_height += (button == 6 ? -0.5 : 0.5);
		make_the_angles(m);
		increase_z(m, -1);
		matrix_multiply(m, -1);
	}
	if (button == 4 || (button == 5 && m->scale - 1 > 0) ||
		button == 7 || button == 6)
		mlx_shit(m);
	return (0);
}
