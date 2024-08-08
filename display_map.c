/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:29:42 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/08 09:48:34 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images2(t_data *data)
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
	the_end(1, data, 0);
}

int	close_window(t_data *data)
{
	free_images2(data);
	free(data->mlx_ptr);
	the_end(1, data, 0);
	return (0);
}

void	put_all_images(t_data *data, char c, void *images)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	while (data->map_real[j])
	{
		i = 0;
		while (data->map_real[j][i])
		{
			if (data->map_real[j][i] && data->map_real[j][i] == c)
				mlx_put_image_to_window(data->mlx_ptr,
					data->mlx_window, images, i * 50, j * 50);
			i++;
		}
		j++;
	}
}

void	put_images(t_data *data)
{
	put_all_images(data, '1', data->wall_image);
	put_all_images(data, '0', data->background_image);
	put_all_images(data, 'P', data->playerright);
	put_all_images(data, 'E', data->exit_image);
	put_all_images(data, 'C', data->collect_image);
}

void	display_map(t_data *data)
{
	number_of_collectibles(data);
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, 50 * data->x, 50 * data->y,
			"so_long");
	images_data(data);
	put_images(data);
	mlx_hook(data->mlx_window, 02, (1L << 0), player_movements, data);
	mlx_hook(data->mlx_window, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}

// void    put_image_player(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     data->background_image = mlx_xpm_file_to_image(data->mlx_ptr,
		// "images/my.xpm", &data->img_width, &data->img_height);
//     while (data->map_real[j])
//     {
//         i = 0;
//         while (data->map_real[j][i])
//         {
//             if (data->map_real[j][i] && data->map_real[j][i] == '0')
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		// data->background_image, i * 50, j * 50);
//             i++;
//         }
//         j++;
//     }

// }

// void    put_image_background(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     data->background_image = mlx_xpm_file_to_image(data->mlx_ptr,
		// "images/my.xpm", &data->img_width, &data->img_height);
//     while (data->map_real[j])
//     {
//         i = 0;
//         while (data->map_real[j][i])
//         {
//             if (data->map_real[j][i] && data->map_real[j][i] == '0')
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		// data->background_image, i * 50, j * 50);
//             i++;
//         }
//         j++;
//     }
// }
