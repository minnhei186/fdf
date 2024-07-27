/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loder_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:26:07 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/07/26 17:11:09 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_ifno_data_free(t_fdf *fdf, char *str, int fd)
{
	if (!str || *str == '\0')
	{
		if (*str == '\0')
			free(str);
		if (close(fd) == -1)
			fdf_error(fdf, "close_error", 1);
		fdf_error(fdf, "no_data", 0);
	}
}
