/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:36:08 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/26 17:15:11 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	fdf_fill_line_loop(int fd, t_fdf *fdf, char *line, char **line_num)
{
	static int	i_height;
	int			j_width;

	fdf->map->array[i_height] = (int *)malloc(sizeof(int) * fdf->map->width);
	if (!(fdf->map->array[i_height]))
	{
		fdf_cppt_free(line_num);
		if (close(fd) == -1)
		{
			free(line);
			fdf_error(fdf, "close_error", 1);
		}
		free(line);
		fdf_error(fdf, "malloc_error", 1);
	}
	j_width = 0;
	while (j_width < fdf->map->width)
	{
		fdf->map->array[i_height][j_width] = ft_atoi(line_num[j_width]);
		j_width++;
	}
	fdf_cppt_free(line_num);
	i_height++;
}

static void	fdf_fill_line(int fd, t_fdf *fdf, char *line)
{
	char	**line_num;
	int		data_count;

	line_num = ft_split(line, ' ');
	if (!line_num)
	{
		free(line);
		if (close(fd) == -1)
			fdf_error(fdf, "close_error", 1);
		fdf_error(fdf, "ft_split_malloc_error", 1);
	}
	data_count = 0;
	while (line_num[data_count])
	{
		data_count++;
	}
	fdf_fill_line_loop(fd, fdf, line, line_num);
}

static void	fdf_read_line(int fd, t_fdf *fdf, char *line)
{
	while (line && *line != '\0')
	{
		fdf_fill_line(fd, fdf, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	fdf_read_map_open(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error(fdf, "open_error", 1);
	line = get_next_line(fd);
	fdf_read_line(fd, fdf, line);
	if (close(fd) == -1)
		fdf_error(fdf, "close_error", 1);
	fdf->map->array[fdf->map->height] = NULL;
}

void	fdf_read_map(t_fdf *fdf, char *filename)
{
	fdf->map->array = (int **)malloc(sizeof(int *) * (fdf->map->height + 1));
	if (!fdf->map->array)
		fdf_error(fdf, "malloc_error", 1);
	fdf_read_map_open(fdf, filename);
}
