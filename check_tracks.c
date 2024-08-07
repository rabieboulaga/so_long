/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tracks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:43:31 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/07 16:04:05 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_data2(t_data *data)
{
	data->playerup = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/playerup.xpm", &data->img_width, &data->img_height);
	data->playerdown = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/playerdown.xpm", &data->img_width, &data->img_height);
	data->exit_image = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/lastexit.xpm", &data->img_width, &data->img_height);
	data->collect_image = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/lastcollect.xpm", &data->img_width, &data->img_height);
}

void	find_item(t_data *data, char c)
{
	int	i;
	int	j;

	j = 0;
	while (data->map_copie[j])
	{
		i = 0;
		while (data->map_copie[j][i] && data->map_copie[j][i] != c)
			i++;
		if (data->map_copie[j][i] == c)
			safe_exit(1, data, 0);
		j++;
	}
}

void	coordinates(t_data *data)
{
	while (data->map_copie[data->yp])
	{
		data->xp = 0;
		while (data->map_copie[data->yp][data->xp]
			&& data->map_copie[data->yp][data->xp] != 'P')
			data->xp++;
		if (data->map_copie[data->yp][data->xp] == 'P')
			break ;
		data->yp++;
	}
	while (data->map_copie[data->ye])
	{
		data->xe = 0;
		while (data->map_copie[data->ye][data->xe]
			&& data->map_copie[data->ye][data->xe] != 'E')
			data->xe++;
		if (data->map_copie[data->ye][data->xe] == 'E')
			break ;
		data->ye++;
	}
}

void	flood_fill_exit(int x, int y, char **str)
{
	if (str[y][x] == 'X' || str[y][x] == 'E')
	{
		str[y][x] = 'Z';
		flood_fill_exit(x + 1, y, str);
		flood_fill_exit(x - 1, y, str);
		flood_fill_exit(x, y + 1, str);
		flood_fill_exit(x, y - 1, str);
	}
}

void	flood_fill(int x, int y, char **str)
{
	if (str[y][x] == '0' || str[y][x] == 'P' || str[y][x] == 'C')
	{
		str[y][x] = 'X';
		flood_fill(x + 1, y, str);
		flood_fill(x - 1, y, str);
		flood_fill(x, y + 1, str);
		flood_fill(x, y - 1, str);
	}
}
