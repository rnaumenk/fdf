/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:19:17 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/28 17:19:18 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_hook5(int keycode, t_m *m)
{
	if (keycode == 84)
	{
		if (m->color_g == 0 && m->tab_on == 1)
			m->color_g = 1;
		else if (m->color_g == 1 && m->tab_on == 1)
			m->color_g = 0;
		change_drawcolor(m);
	}
	if (keycode == 85)
	{
		if (m->color_b == 0 && m->tab_on == 1)
			m->color_b = 1;
		else if (m->color_b == 1 && m->tab_on == 1)
			m->color_b = 0;
		change_drawcolor(m);
	}
	mlx_shit(m);
	return (0);
}

static int		key_hook4(int keycode, t_m *m)
{
	if (keycode == 48)
	{
		if (m->tab_on == 0)
			m->tab_on = 1;
		else if (m->tab_on == 1)
			m->tab_on = 0;
	}
	if (keycode == 83)
	{
		if (m->color_r == 0 && m->tab_on == 1)
			m->color_r = 1;
		else if (m->color_r == 1 && m->tab_on == 1)
			m->color_r = 0;
		change_drawcolor(m);
	}
	return (key_hook5(keycode, m));
}

static int		key_hook3(int keycode, t_m *m)
{
	if (keycode == 78)
	{
		m->win_increase = 0;
		if (m->w_w - m->w_w * (m->win_decrease + 1) * 0.045 > 0)
		{
			m->w_w -= m->w_w * ++m->win_decrease * 0.045;
			m->right = (m->w_w - m->initial_w_w) * 0.1;
			m->left = 0;
		}
		if (m->w_h - m->w_h * (m->win_decrease + 1) * 0.025 > 0)
		{
			m->w_h -= m->w_h * ++m->win_decrease * 0.025;
			m->down = (m->w_w - m->initial_w_w) * 0.05;
			m->up = 0;
		}
		m->destroy_win = 1;
	}
	if (keycode == 67)
	{
		default_options(m);
		m->destroy_win = 1;
	}
	return (key_hook4(keycode, m));
}

static int		key_hook2(int keycode, t_m *m)
{
	if (keycode == 69)
	{
		m->win_decrease = 0;
		if (m->w_w + (m->win_increase * 0.05 *
			(2560 - m->w_w)) < 2560)
		{
			m->w_w += (m->w_w + (++m->win_increase * 0.05 *
				(2560 - m->w_w)) > 2560 ? 2560 : (m->win_increase * 0.05 *
				(2560 - m->w_w)));
			m->right = (m->w_w - m->initial_w_w) * 0.1;
			m->left = 0;
		}
		if (m->w_h + (m->win_increase * 0.05 *
			(1315 - m->w_h)) < 1315)
		{
			m->w_h += (m->w_h + (m->win_increase * 0.05 *
				(1315 - m->w_h)) > 1315 ? 1315 : (m->win_increase * 0.05 *
				(1315 - m->w_h)));
			m->up = 0;
			m->down = (m->w_w - m->initial_w_w) * 0.1;
		}
		m->destroy_win = 1;
	}
	return (key_hook3(keycode, m));
}

int				key_hook(int keycode, t_m *m)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		m->right += 0.01 * m->w_w;
	if (keycode == 0)
		m->left += 0.01 * m->w_w;
	if (keycode == 13)
		m->up += 0.01 * m->w_h;
	if (keycode == 1)
		m->down += 0.01 * m->w_h;
	if (keycode == 126 || keycode == 125 ||
		keycode == 124 || keycode == 123)
	{
		if (keycode == 126)
			m->turn_up += 0.05;
		if (keycode == 125)
			m->turn_down += 0.05;
		if (keycode == 124)
			m->turn_right += 0.05;
		if (keycode == 123)
			m->turn_left += 0.05;
		make_the_angles(m);
		matrix_multiply(m, -1);
	}
	return (key_hook2(keycode, m));
}
