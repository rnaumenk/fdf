/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:38:40 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:38:43 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw(t_m *m)
{
	int		i;

	i = -1;
	while (++i < m->quantity)
	{
		mlx_pixel_put(m->mlx, m->win, m->d[i].win_x, m->d[i].win_y,
			m->d[i].color);
		if (i < m->quantity - 1 && (i + 1) % m->width)
			draw_line_x(m, i);
		if (i + m->width < m->quantity)
			draw_line_y(m, i);
	}
}

static void		dots_in_the_window(t_m *m, int i)
{
	int		j;
	int		l;

	j = 0;
	l = 0;
	if (m->quantity <= 1)
		error(1);
	while (++i < m->quantity)
	{
		if (j == m->width)
		{
			j = 0;
			l++;
		}
		m->d[i].win_x = (m->w_w * 0.25) + (int)(m->d[i].x_tr * m->scale) +
			m->w_w * 0.1 + m->right - m->left;
		m->d[i].win_y = (m->w_h * 0.25) + (int)(m->d[i].y_tr * m->scale) -
			m->w_h * 0.1 - m->up + m->down;
		j++;
	}
}

static int		string_put2(t_m *m)
{
	if (m->color_g == 0 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 60, 15263976,
			"GREEN (NUM2)");
	else if (m->color_g == 1 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 60, 65280, "GREEN (NUM2)");
	if (m->color_b == 0 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 30, 15263976,
			"BLUE (NUM3)");
	else if (m->color_b == 1 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 30, 255, "BLUE (NUM3)");
	return (0);
}

static int		string_put(t_m *m)
{
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 20, 15263976,
			"MOVE: W A S D / mouse");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 40, 15263976,
			"SCALE: scroll up/down");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 60, 15263976,
			"HEIGHT: scroll left/right");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 80, 15263976, "TURN: arrows");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 100, 15263976, "WIN_SIZE: + / -");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 120, 15263976, "DEFAULT OPTIONS: *");
	if (m->tab_on == 0)
		mlx_string_put(m->mlx, m->win, 20, 140, 15263976, "DRAW MODE: TAB");
	if (m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, 20, 65280, "NORMAL MODE: TAB");
	if (m->color_r == 0 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 90, 15263976, "RED (NUM1)");
	else if (m->color_r == 1 && m->tab_on == 1)
		mlx_string_put(m->mlx, m->win, 20, m->w_h - 90, 16711680, "RED (NUM1)");
	return (string_put2(m));
}

void			mlx_shit(t_m *m)
{
	if (!m->mlx)
		m->mlx = mlx_init();
	if (m->win && m->destroy_win)
	{
		mlx_destroy_window(m->mlx, m->win);
		m->win = 0;
		m->destroy_win = 0;
	}
	else if (m->win && !m->destroy_win)
		mlx_clear_window(m->mlx, m->win);
	if (!m->win)
		m->win = mlx_new_window(m->mlx, m->w_w, m->w_h, "mirror");
	string_put(m);
	dots_in_the_window(m, -1);
	draw(m);
	mlx_hook(m->win, 2, 5, key_hook, m);
	mlx_hook(m->win, 17, 1L << 17, win_exit, m);
	mlx_hook(m->win, 4, 0, mouse_hook, m);
	mlx_hook(m->win, 5, 0, mouse_off, m);
	mlx_hook(m->win, 6, 0, mouse_move, m);
}
