/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:52:31 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 15:51:25 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	convert(t_coord_value **coords_stack, t_map *map)
{
	t_coord_value	*coords;
	int				i;
	int				arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)malloc(arr_size);
	map->colors_arr = (int *)malloc(arr_size);
	if (!map->coords_arr || !map->colors_arr)
		exit(ft_printf("Convert Error\n"));
	i = map->width * map->height - 1;
	while (1)
	{
		if (!(*coords_stack))
			break ;
		coords = pop(coords_stack);
		map->coords_arr[i] = coords->z;
		map->colors_arr[i] = coords->color;
		if (coords->z > map->z_max)
			map->z_max = coords->z;
		if (coords->z < map->z_min)
			map->z_min = coords->z;
		i--;
		free(coords);
	}
}
