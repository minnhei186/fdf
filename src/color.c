/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:00:18 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 13:43:40 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	fdf_out_trgb(t_color color)
{
	return (fdf_create_trgb(color.t, color.r, color.g, color.b));
}

t_color	fdf_get_color(int z, int z_min, int z_max)
{
	t_color	min;
	t_color	max;
	t_color	color;
	float	ratio;

	min.t = 0;
	min.r = 0;
	min.g = 0;
	min.b = 255;
	max.t = 0;
	max.r = 255;
	max.g = 0;
	max.b = 0;
	if (z_max == z_min)
		ratio = 0;
	else
		ratio = (float)(z - z_min) / (float)(z_max - z_min);
	color.r = min.r + (max.r - min.r) * ratio;
	color.g = min.g + (max.g - min.g) * ratio;
	color.b = min.b + (max.b - min.b) * ratio;
	color.t = 0;
	return (color);
}

float	fdf_position_ratio(t_bresenham current, t_point from, t_point to)
{
	int		dx;
	int		dy;
	float	ratio;

	dx = to.x - from.x;
	dy = to.y - from.y;
	if (fdf_abs(dx) > fdf_abs(dy))
	{
		if (from.x != to.x)
			ratio = ((float)(current.x - from.x) / (float)(to.x - from.x));
		else
			return (0);
	}
	else
	{
		if (from.y != to.y)
			ratio = (((float)current.y - from.y) / ((float)to.y - from.y));
		else
			return (0);
	}
	return (ratio);
}

t_color	fdf_get_current_color(t_fdf *fdf, t_bresenham current, t_point from,
		t_point to)
{
	t_color	f_color;
	t_color	to_color;
	t_color	c_color;
	float	c_ratio;

	f_color = fdf_get_color(from.z, fdf->map->min, fdf->map->max);
	to_color = fdf_get_color(to.z, fdf->map->min, fdf->map->max);
	c_ratio = fdf_position_ratio(current, from, to);
	c_color.r = f_color.r + ((float)((to_color.r) - (f_color.r))) * (c_ratio);
	c_color.g = f_color.g + ((float)((to_color.g) - (f_color.g))) * (c_ratio);
	c_color.b = f_color.b + ((float)((to_color.b) - (f_color.b))) * (c_ratio);
	c_color.t = 0;
	return (c_color);
}
