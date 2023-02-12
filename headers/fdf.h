/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:58 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/10 18:47:44 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT	1024
# define WIDTH	1920
# define MENU_WIDTH	250

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef enum s_projection
{
	ISO,
	PARALLEL
}		t_projection;

typedef struct s_drawp
{
	double			x;
	double			y;
}				t_drawp;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_coord_value
{
	struct s_coord_value	*next;
	int						z;
	int						color;
}				t_coord_value;

typedef struct s_map
{
	int	height;
	int	width;
	int	*coords_arr;
	int	*colors_arr;
	int	z_min;
	int	z_max;
}				t_map;

typedef struct s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		z;
	int		previous_x;
	int		previous_y;
}			t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}				t_fdf;

t_map			*map_init(void);
t_fdf			*fdf_init(t_map *map);
t_coord_value	*new_coord(char *coords_arr);
t_coord_value	*pop(t_coord_value **stack);
t_camera		*camera_init(t_fdf *fdf);
t_point			new_point(int x, int y, t_map *map);
t_point			project(t_point p, t_fdf *fdf);
int				ft_atoi_base(const char *str);
void			read_map(int fd, t_coord_value **coords, t_map *map);
int				get_default_color(int z, t_map *map);
int				get_color(t_point current, t_point start,
					t_point end);
int				get_index(int x, int y, int width);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				key_press(int key, void *param);
int				close_(void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			parse_line(t_coord_value **coords,
					t_map *map, char **coords_arr);
void			free_double(char **str);
void			convert(t_coord_value **coords_stack, t_map *map);
void			push(t_coord_value **lst, t_coord_value *new);
void			draw(t_map *map, t_fdf *fdf);
void			rotate_y(int *x, int *z, double theta);
void			rotate_x(int *y, int *z, double theta);
void			rotate_z(int *x, int *y, double theta);
void			iso(int *x, int *y, int z);
void			draw_background(t_fdf *fdf);
void			setup_controls(t_fdf *fdf);
void			zoom(int key, t_fdf *fdf);
void			rotate(int key, t_fdf *fdf);
void			pit(int key, t_fdf *fdf);
void			change_projection(int key, t_fdf *fdf);
void			move(int key, t_fdf *fdf);
void			print_menu(t_fdf *fdf);
char			**ft_split(char const *s, char c);

#endif