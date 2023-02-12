/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:28:56 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 16:11:00 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int ac, char **av)
{
	int				fd;
	t_map			*map;
	t_coord_value	*coords;
	t_fdf			*fdf;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			exit(ft_printf("Incorrect Map File!\n"));
		map = map_init();
		coords = NULL;
		read_map(fd, &coords, map);
		fdf = fdf_init(map);
		convert(&coords, map);
		fdf->camera = camera_init(fdf);
		draw(fdf->map, fdf);
		setup_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_printf("Incorrect Argument Number!\n");
	return (0);
}
