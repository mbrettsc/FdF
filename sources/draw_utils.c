/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:13:49 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 18:56:20 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../headers/color.h"

t_point	project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->camera->alpha);
	rotate_y(&p.x, &p.z, fdf->camera->beta);
	rotate_z(&p.x, &p.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
	p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->y_offset;
	return (p);
}

void	draw_background(t_fdf *fdf)
{
	int	*b_ground;
	int	i;

	b_ground = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			b_ground[i] = MENU_BACKGROUND;
		else
			b_ground[i] = BACKGROUND;
		i++;
	}
}

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	p;
	int		i;

	i = get_index(x, y, map->width);
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[i];
	if (map->colors_arr[i] == -1)
		p.color = get_default_color(p.z, map);
	else
		p.color = map->colors_arr[i];
	return (p);
}
