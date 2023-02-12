/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:40:46 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 16:11:41 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

t_coord_value	*new_coord(char *coords_arr)
{
	t_coord_value	*coords;
	char			**line;

	coords = (t_coord_value *)malloc(sizeof(t_coord_value));
	if (!coords)
		exit(ft_printf("Memmory Allocation Error\n"));
	line = ft_split(coords_arr, ',');
	if (!line)
		exit(ft_printf("Map Parsing Error!\n"));
	coords->z = ft_atoi(line[0]);
	if (line[1])
		coords->color = ft_atoi_base(line[1]);
	else
		coords->color = -1;
	coords->next = NULL;
	free_double(line);
	return (coords);
}

void	parse_line(t_coord_value **coords, t_map *map, char **coords_arr)
{
	int	width;

	width = 0;
	while (*coords_arr)
	{
		push(coords, new_coord(*(coords_arr++)));
		width++;
	}
	if (map->height == 0 || map->width != width)
		map->width = width;
	else if (map->width != width)
		exit(ft_printf("Map Parsing Error!\n"));
}

void	read_map(int fd, t_coord_value **coords, t_map *map)
{
	char	*line;
	char	**coords_arr;

	line = get_next_line(fd);
	while (line != NULL)
	{
		coords_arr = ft_split(line, ' ');
		if (!coords_arr)
			exit(ft_printf("Map Parsing Error!\n"));
		parse_line(coords, map, coords_arr);
		map->height++;
		free_double(coords_arr);
		free(line);
		line = get_next_line(fd);
	}
}
