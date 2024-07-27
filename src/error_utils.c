/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:16:19 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 13:10:05 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_return_error(char *err_msg, int system_err)
{
	if (system_err)
		perror(err_msg);
	else
		ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	fdf_cpt_error(t_fdf *fdf, char *cpt, char *err_msg, int system_err)
{
	if (cpt)
		free(cpt);
	fdf_error(fdf, err_msg, system_err);
}

void	fdf_ipt_error(t_fdf *fdf, int *ipt, char *err_msg, int system_err)
{
	if (ipt)
		free(ipt);
	fdf_error(fdf, err_msg, system_err);
}

void	fdf_error(t_fdf *fdf, char *err_msg, int system_err)
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
	fdf_return_error(err_msg, system_err);
}
