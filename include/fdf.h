/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:52:19 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 16:20:49 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ZOOM_WHEIGHT 10
#define KEY_ESC  65307

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		reverse;
}			t_point;

typedef struct s_bresenham
{
	int		x;
	int		y;
	int		err;
	int		sx;
	int		sy;
}			t_bresenham;

typedef struct s_map
{
	int		height;
	int		width;
	int		**array;
	int		max;
	int		min;
}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		steep;
	t_map	*map;
}			t_fdf;

// fdf_utils
int			fdf_min(int a, int b);
int			fdf_abs(int a);

// memory_free
void		fdf_ifno_data_free(t_fdf *fdf, char *str, int fd);
void		fdf_cppt_free(char **ppt);
void		fdf_ippt_free(int **ppt);

void		fdf_t_map_free(t_fdf *fdf);
void		fdf_free(t_fdf *fdf);

// error_utils
void		fdf_return_error(char *err_msg, int system_err);
void		fdf_cpt_error(t_fdf *fdf, char *cpt, char *err_msg, int system_err);
void		fdf_ipt_error(t_fdf *fdf, int *ipt, char *err_msg, int system_err);
void		fdf_error(t_fdf *fdf, char *err_msg, int system_err);

// read_map
void		fdf_read_map(t_fdf *fdf, char *filename);

// data_loder_utils
int			fdf_read_count(int fd, char *str);
void		fdf_get_height(t_fdf *fdf, char *file_name);
int			fdf_read_width(char *str);
void		fdf_get_width(t_fdf *fdf, char *filename);
void		fdf_get_z_min_max(t_fdf *fdf);

// data_loder
void		fdf_data_lodo(t_fdf *fdf, char *filename);

// ft_line_draw
t_bresenham	fdf_init_bresenham(t_point from, t_point to);
t_bresenham	fdf_update_bresenham(t_bresenham current, t_point to);

// fdf_color
int			fdf_out_trgb(t_color color);
t_color		fdf_get_current_color(t_fdf *fdf, t_bresenham current, t_point from,
				t_point to);

// fdf_draw
void		fdf_draw_line(t_fdf *fdf, t_point from, t_point to);
t_point		fdf_draw_point(int x, int y, t_fdf *fdf);
void		fdf_draw_grid(t_fdf *fdf);

// fdf_line_draw
void		fdf_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

// hook
int			fdf_close_hook(int keycode, t_fdf *fdf);
void		fdf_hook(t_fdf *fdf);

// fdf
void		fdf_data_init(t_fdf *fdf);
void		fdf_info_mlx_init(t_fdf *fdf, char *file_path);

#endif
