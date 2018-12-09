/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:03:54 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/10 14:03:55 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include "./libft/libft.h"

typedef struct		s_dot
{
	double	x;
	double	y;
	double	z;
	double	x_tr;
	double	y_tr;
	double	z_tr;
	int		color;
	int		win_x;
	int		win_y;
}					t_dot;

typedef struct		s_m
{
	t_dot	*d;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		quantity;
	double	*a;
	int		w_w;
	int		w_h;
	int		scale;
	int		next;
	int		right;
	int		left;
	int		down;
	int		up;
	int		win_increase;
	int		win_decrease;
	int		initial_w_w;
	int		initial_w_h;
	double	turn_right;
	double	turn_left;
	double	turn_up;
	double	turn_down;
	double	increase_height;
	int		mouse_on;
	int		mouse_x;
	int		mouse_y;
	int		tab_on;
	int		color;
	int		color_r;
	int		color_g;
	int		color_b;
	int		red;
	int		green;
	int		blue;
	int		destroy_win;
}					t_m;

void				mlx_shit(t_m *m);
int					key_hook(int keycode, t_m *m);
int					mouse_hook(int button, int x, int y, t_m *m);
void				default_options(t_m *m);
void				mlx_shit(t_m *m);
void				increase_z(t_m *m, int i);
void				make_the_angles(t_m *m);
void				matrix_multiply(t_m *m, int i);
void				window_and_scale_calculation(t_m *m);
int					color_calc(t_m *m, int i, int next, double br);
void				create_the_dots(char *s, t_m *m, int count, int y);
int					mouse_off(int button, int x, int y, t_m *m);
int					mouse_move(int x, int y, t_m *m);
void				change_drawcolor(t_m *m);
void				error(int nb);
void				draw_line_x(t_m *m, int i);
void				draw_line_y(t_m *m, int i);
void				wu_shit_for_y_longer(t_m *m, int i, double x, double y);
void				wu_shit_for_x_longer(t_m *m, int i, double y, double x);
void				horizontal_line(t_m *m, double x, int i, int next);
void				vertical_line(t_m *m, double y, int i, int next);
int					mouse_hook(int button, int x, int y, t_m *m);
int					mouse_move(int x, int y, t_m *m);
int					mouse_off(int button, int x, int y, t_m *m);
int					win_exit(t_m *m);
void				free_split(char ***temp);

#endif
