/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:43:56 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/27 13:52:09 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_info_mlx_init(t_fdf *fdf, char *file_path)
{
	char	*title;

	title = ft_strjoin("FfF -", file_path);
	if (!title)
		fdf_error(fdf, "ft_strjoin_malloc_error", 1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		fdf_error(fdf, "mlx_init_error", 1);
		free(title);
	}
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, title);
	if (!fdf->win)
	{
		fdf_error(fdf, "win_init_error", 1);
		free(title);
	}
	free(title);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		fdf_error(fdf, "img_init_error", 1);
}

void	fdf_null_init(t_fdf *fdf)
{
	fdf->data_addr = NULL;
	fdf->map = NULL;
}

void	fdf_data_init(t_fdf *fdf)
{
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line,
			&fdf->endian);
	if (!fdf->data_addr)
		fdf_error(fdf, "data_addr_error", 1);
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		fdf_error(fdf, "map_init_error", 1);
	fdf->map->height = 0;
	fdf->map->width = 0;
	fdf->map->array = NULL;
	fdf->map->max = 0;
	fdf->map->min = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		fdf_return_error("malloc_error", 1);
	if (argc != 2)
		fdf_error(fdf, "Usage:.fdf <file_name>", 0);
	fdf_info_mlx_init(fdf, argv[1]);
	fdf_null_init(fdf);
	fdf_data_init(fdf);
	fdf_data_lodo(fdf, argv[1]);
	fdf_draw_grid(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	fdf_hook(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
