/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:07:00 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 15:56:07 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/color.h"
#include "../headers/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 90, y += 20, TEXT_COLOR, "Manual");
	mlx_string_put(mlx, win, 15, y += 40, TEXT_COLOR, "Zoom: Scroll or */-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Pit: K/L Keys");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate with Mouse:");
	mlx_string_put(mlx, win, 57, y += 30, TEXT_COLOR, "Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate with Keyboard:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 3/7");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
	mlx_string_put(mlx, win, 90, y += 40, TEXT_COLOR, "RTFM!");
}
