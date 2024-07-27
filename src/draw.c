/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:08:43 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/26 16:28:25 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_line(t_fdf *fdf, t_point from, t_point to)
{
	t_bresenham	current;
	t_color		color;

	current = fdf_init_bresenham(from, to);
	while (!(current.x == to.x && current.y == to.y))
	{
		if ((current.x >= 0 && current.x < WIDTH) && (current.y >= 0
				&& current.y < HEIGHT))
		{
			color = fdf_get_current_color(fdf, current, from, to);
			fdf_mlx_pixel_put(fdf, current.x, current.y, fdf_out_trgb(color));
		}
		current = fdf_update_bresenham(current, to);
	}
}

t_point	fdf_draw_point(int x, int y, t_fdf *fdf)
{
	t_point	draw_p;
	int		zoom;
	int		offset_x;
	int		offset_y;

	zoom = ZOOM_WHEIGHT;
	offset_x = (WIDTH / 2) - ((fdf->map->width - 1) * zoom / 2);
	offset_y = (HEIGHT / 2) - ((fdf->map->height - 1) * zoom / 2);
	draw_p.z = (fdf->map->array[y][x]);
	x = (x * zoom);
	y = (y * zoom);
	draw_p.x = (x - y) * cos(M_PI / 6);
	draw_p.y = (x + y) * sin(M_PI / 6) - draw_p.z;
	draw_p.x += offset_x;
	draw_p.y += offset_y;
	draw_p.reverse = 0;
	return (draw_p);
}

void	fdf_draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				fdf_draw_line(fdf, fdf_draw_point(x, y, fdf), fdf_draw_point((x
							+ 1), y, fdf));
			if (y != fdf->map->height - 1)
				fdf_draw_line(fdf, fdf_draw_point(x, y, fdf), fdf_draw_point(x,
						(y + 1), fdf));
			x++;
		}
		y++;
	}
}
