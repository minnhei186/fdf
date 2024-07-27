/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loder_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <hosokawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:29:15 by hosokawa          #+#    #+#             */
/*   Updated: 2024/07/26 18:35:00 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_read_count(int fd, char *str)
{
	int	count;

	count = 0;
	while (str && *str != '\0')
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	if (str)
		free(str);
	return (count);
}

void	fdf_get_height(t_fdf *fdf, char *file_name)
{
	int		fd;
	char	*str;
	int		count;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fdf_error(fdf, "open_error", 1);
	str = get_next_line(fd);
	fdf_ifno_data_free(fdf, str, fd);
	count = fdf_read_count(fd, str);
	if (close(fd) == -1)
		fdf_error(fdf, "close_error", 1);
	fdf->map->height = count;
}

int	fdf_read_width(char *str)
{
	int		width;
	char	**split_line;
	char	**temp;

	if (str == NULL)
		return (0);
	width = 0;
	split_line = ft_split(str, ' ');
	if (!split_line)
	{
		free(str);
		return (-1);
	}
	temp = split_line;
	while (*split_line && **split_line != '\n')
	{
		width++;
		split_line++;
	}
	fdf_cppt_free(temp);
	return (width);
}

void	fdf_get_width(t_fdf *fdf, char *filename)
{
	int		fd;
	int		check_width;
	int		width;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error(fdf, "open_error", 1);
	str = get_next_line(fd);
	check_width = fdf_read_width(str);
	if (check_width == -1)
		fdf_error(fdf, "split_malloc_error", 1);
	width = check_width;
	while (str != NULL)
	{
		free(str);
		if (check_width != width)
			fdf_error(fdf, "data_integrity_error", 0);
		str = get_next_line(fd);
		width = fdf_read_width(str);
	}
	if (close(fd) == -1)
		fdf_error(fdf, "close_error", 1);
	fdf->map->width = check_width;
}

void	fdf_get_z_min_max(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->map->max = fdf->map->array[0][0];
	fdf->map->min = fdf->map->array[0][0];
	i = 0;
	while (fdf->map->array[i])
	{
		j = fdf->map->width - 1;
		while (j >= 0)
		{
			if (fdf->map->max < fdf->map->array[i][j])
				fdf->map->max = fdf->map->array[i][j];
			j--;
		}
		j = fdf->map->width - 1;
		while (j >= 0)
		{
			if (fdf->map->min > fdf->map->array[i][j])
				fdf->map->min = fdf->map->array[i][j];
			j--;
		}
		i++;
	}
}
