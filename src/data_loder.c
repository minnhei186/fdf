/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:31:50 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/26 17:03:28 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_data_lodo(t_fdf *fdf, char *filename)
{
	fdf_get_height(fdf, filename);
	fdf_get_width(fdf, filename);
	fdf_read_map(fdf, filename);
	fdf_get_z_min_max(fdf);
}
