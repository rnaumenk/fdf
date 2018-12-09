/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:58:38 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/01/06 15:58:40 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_options(t_m *m)
{
	m->destroy_win = 0;
	m->right = 0;
	m->left = 0;
	m->up = 0;
	m->down = 0;
	m->win_increase = 0;
	m->win_decrease = 0;
	m->turn_up = 0;
	m->turn_down = 0;
	m->turn_right = 0;
	m->turn_left = 0;
	m->increase_height = 1;
	m->mouse_on = 0;
	m->tab_on = 0;
	m->color_r = 0;
	m->color_g = 0;
	m->color_b = 0;
	m->color = 16777215;
	make_the_angles(m);
	increase_z(m, -1);
	matrix_multiply(m, -1);
	window_and_scale_calculation(m);
	m->initial_w_w = m->w_w;
	m->initial_w_h = m->w_h;
}

void	create_the_dots(char *s, t_m *m, int count, int y)
{
	int		x;
	char	*line;
	char	**temp;
	int		fd;

	if ((fd = open(s, O_RDONLY)) == -1)
		error(4);
	if (!(m->d = (t_dot*)malloc(sizeof(t_dot) * m->quantity)))
		error(6);
	while (get_next_line(fd, &line) == 1 && ++y >= 0)
	{
		temp = ft_strsplit(line, ' ');
		x = -1;
		while (temp[++x])
		{
			m->d[++count].x = (double)x;
			m->d[count].y = (double)y;
			m->d[count].z = ft_atoi(temp[x]);
			m->d[count].color = (ft_strchr(temp[x], 'x') ?
				ft_atoi_base(ft_strchr(temp[x], 'x') + 1, 16) : 16777215);
		}
		free_split(&temp);
		ft_strdel(&line);
	}
	close(fd);
}

void	check_the_file(int fd, t_m *m, int count)
{
	char	*line;
	int		i;
	char	**temp;
	int		height;

	height = 1;
	while (get_next_line(fd, &line))
	{
		temp = ft_strsplit(line, ' ');
		i = 0;
		while (temp[i])
			i++;
		if (i != count)
			error(2);
		free_split(&temp);
		ft_strdel(&line);
		height++;
	}
	m->height = height;
	m->width = count;
	m->quantity = height * count;
}

void	learn_the_size(t_m *m, int fd)
{
	char	*line;
	char	**temp;
	int		count;

	if (get_next_line(fd, &line) != 1)
		error(5);
	temp = ft_strsplit(line, ' ');
	count = 0;
	while (temp[count])
		count++;
	free_split(&temp);
	ft_strdel(&line);
	check_the_file(fd, m, count);
	close(fd);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_m			*m;

	if (argc == 1 || argc > 2)
		error(3);
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		error(6);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(4);
	m->mlx = 0;
	m->win = 0;
	learn_the_size(m, fd);
	create_the_dots(argv[1], m, -1, -1);
	default_options(m);
	mlx_shit(m);
	mlx_loop(m->mlx);
	return (0);
}
