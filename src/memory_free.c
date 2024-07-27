/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:24:48 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 13:52:23 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_cppt_free(char **ppt)
{
	char	**tmp;

	tmp = ppt;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(ppt);
}

void	fdf_ippt_free(int **ppt)
{
	int	**tmp;

	tmp = ppt;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(ppt);
}

void	fdf_t_map_free(t_fdf *fdf)
{
	if (fdf->map && fdf->map->array)
		fdf_ippt_free(fdf->map->array);
	free(fdf->map);
}

void	fdf_free(t_fdf *fdf)
{
	if (fdf->map)
		fdf_t_map_free(fdf);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->mlx);
	free(fdf);
}
