/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:44:04 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 16:15:38 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	rotate_x(int *y, int *z, double theta)
{
	int	previous_y;
	int	previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(theta) + previous_z * sin(theta);
	*z = -previous_y * sin(theta) + previous_z * cos(theta);
}

void	rotate_y(int *x, int *z, double theta)
{
	int	previous_x;
	int	previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(theta) + previous_z * sin(theta);
	*z = -previous_x * sin(theta) + previous_z * cos(theta);
}

void	rotate_z(int *x, int *y, double theta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(theta) - previous_y * sin(theta);
	*y = previous_x * sin(theta) + previous_y * cos(theta);
}

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
