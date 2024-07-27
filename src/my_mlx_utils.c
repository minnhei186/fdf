/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:20:15 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/26 16:34:40 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * fdf->size_line + x * (fdf->bpp / 8);
	dst = fdf->data_addr + offset;
	*(unsigned int *)dst = color;
}
