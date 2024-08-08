/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:16 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/08 09:30:05 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_moves(int num)
{
	if (num > 9)
		put_moves(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	put_str(char *str, int num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	put_moves(num);
	write(1, "\n", 1);
}

void	free_images(t_data *data)
{
	if (data->exit_image != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit_image);
	if (data->collect_image != NULL)
		mlx_destroy_image(data->mlx_ptr, data->collect_image);
	if (data->playerdown != NULL)
		mlx_destroy_image(data->mlx_ptr, data->playerdown);
	if (data->playerleft != NULL)
		mlx_destroy_image(data->mlx_ptr, data->playerleft);
	if (data->playerright != NULL)
		mlx_destroy_image(data->mlx_ptr, data->playerright);
	if (data->playerup != NULL)
		mlx_destroy_image(data->mlx_ptr, data->playerup);
	if (data->wall_image != NULL)
		mlx_destroy_image(data->mlx_ptr, data->wall_image);
	if (data->background_image != NULL)
		mlx_destroy_image(data->mlx_ptr, data->background_image);
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	write (1, "Error: Required Pictures Not Found\n", 36);
	the_end(1, data, 0);
}

void	images_data(t_data *data)
{
	data->wall_image = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/img.xpm", &data->img_width, &data->img_height);
	if (data->wall_image == NULL)
		free_images(data);
	data->background_image = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/my.xpm", &data->img_width, &data->img_height);
	if (data->wall_image == NULL)
		free_images(data);
	data->playerleft = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/playerleft.xpm", &data->img_width, &data->img_height);
	if (data->playerleft == NULL)
		free_images(data);
	data->playerright = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/playerright.xpm", &data->img_width, &data->img_height);
	if (data->playerright == NULL)
		free_images(data);
	images_data2(data);
}

void	number_of_collectibles(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->map_real[j])
	{
		i = 0;
		while (data->map_real[j][i])
		{
			if (data->map_real[j][i] == 'C')
				data->collectibles++;
			i++;
		}
		j++;
	}
}
