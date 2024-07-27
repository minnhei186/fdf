/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:19:49 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 13:43:55 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bresenham	fdf_init_bresenham(t_point from, t_point to)
{
	t_bresenham	current;
	int			dx;
	int			dy;

	dx = fdf_abs(to.x - from.x);
	dy = fdf_abs(to.y - from.y);
	current.x = from.x;
	current.y = from.y;
	if (dx > dy)
		current.err = dx / 2;
	else
		current.err = (-dy) / 2;
	if (from.x < to.x)
		current.sx = 1;
	else
		current.sx = -1;
	if (from.y < to.y)
		current.sy = 1;
	else
		current.sy = -1;
	return (current);
}

t_bresenham	fdf_update_bresenham(t_bresenham current, t_point to)
{
	int	tmp_err;
	int	dx;
	int	dy;

	dx = fdf_abs(to.x - current.x);
	dy = fdf_abs(to.y - current.y);
	tmp_err = current.err;
	if (tmp_err > -dx)
	{
		current.err -= dy;
		current.x += current.sx;
	}
	if (tmp_err < dy)
	{
		current.err += dx;
		current.y += current.sy;
	}
	return (current);
}
