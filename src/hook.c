/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:12:56 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 16:37:35 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		if (fdf->map)
			fdf_t_map_free(fdf);
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		if (fdf->mlx)
			free(fdf->mlx);
		free(fdf);
		exit(0);
	}
	return (0);
}

int	fdf_close_mouse_hook(t_fdf *fdf)
{
	if (fdf->map)
		fdf_t_map_free(fdf);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
	exit(0);
	return (0);
}

void	fdf_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, fdf_close_key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, fdf_close_mouse_hook, fdf);
}
