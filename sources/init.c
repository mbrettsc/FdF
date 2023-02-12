/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:31:58 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 16:10:41 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_printf("Memmory Allocation Error!\n");
	map->colors_arr = NULL;
	map->coords_arr = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit(ft_printf("Memmory Allocation Error!\n"));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Martin_FDF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->size_line, &fdf->endian);
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		return (NULL);
	return (fdf);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->projection = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divisor = 1;
	camera->zoom = HEIGHT / fdf->map->height / 2;
	return (camera);
}
