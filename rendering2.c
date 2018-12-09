/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:42:29 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/30 17:42:30 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vertical_line(t_m *m, double y, int i, int next)
{
	double	dy;

	dy = m->d[i + next].win_y - m->d[i].win_y;
	if (dy >= 0)
	{
		while (++y < m->d[i + next].win_y)
			mlx_pixel_put(m->mlx, m->win, m->d[i].win_x, (int)y,
				color_calc(m, i, next, 1));
	}
	else
	{
		while (--y > m->d[i + next].win_y)
			mlx_pixel_put(m->mlx, m->win, m->d[i].win_x, (int)y,
				color_calc(m, i, next, 1));
	}
}

void	horizontal_line(t_m *m, double x, int i, int next)
{
	double	dx;

	dx = m->d[i + next].win_x - m->d[i].win_x;
	if (dx >= 0)
	{
		while (++x < m->d[i + next].win_x)
			mlx_pixel_put(m->mlx, m->win, (int)x, m->d[i].win_y,
				color_calc(m, i, next, 1));
	}
	else
	{
		while (--x > m->d[i + next].win_x)
			mlx_pixel_put(m->mlx, m->win, (int)x, m->d[i].win_y,
				color_calc(m, i, next, 1));
	}
}

void	wu_shit_for_x_longer(t_m *m, int i, double y, double x)
{
	int		module;

	module = (int)(y * 10) % 10;
	if (!module)
		mlx_pixel_put(m->mlx, m->win, (int)x, (int)y,
			color_calc(m, i, m->next, 1));
	else if (module)
	{
		mlx_pixel_put(m->mlx, m->win, (int)x, (int)(y + 1),
			color_calc(m, i, m->next, module * 0.1));
		mlx_pixel_put(m->mlx, m->win, (int)x, (int)y,
			color_calc(m, i, m->next, (10 - module) * 0.1));
	}
}

void	wu_shit_for_y_longer(t_m *m, int i, double x, double y)
{
	int		module;

	module = (int)(x * 10) % 10;
	if (!module)
		mlx_pixel_put(m->mlx, m->win, (int)x, (int)y,
			color_calc(m, i, m->next, 1));
	else if (module)
	{
		mlx_pixel_put(m->mlx, m->win, (int)(x + 1), (int)y,
			color_calc(m, i, m->next, module * 0.1));
		mlx_pixel_put(m->mlx, m->win, (int)x, (int)y,
			color_calc(m, i, m->next, (10 - module) * 0.1));
	}
}
