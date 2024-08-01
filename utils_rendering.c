/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:16 by rboulaga          #+#    #+#             */
/*   Updated: 2024/07/31 15:20:40 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    images_data(t_data *data)
{
    data->wall_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/img.xpm", &data->img_width, &data->img_height);
    data->background_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/my.xpm", &data->img_width, &data->img_height);
    data->playerleft = mlx_xpm_file_to_image(data->mlx_ptr, "images/playerleft.xpm", &data->img_width, &data->img_height);
    data->playerright = mlx_xpm_file_to_image(data->mlx_ptr, "images/playerright.xpm", &data->img_width, &data->img_height);
    data->playerup = mlx_xpm_file_to_image(data->mlx_ptr, "images/playerup.xpm", &data->img_width, &data->img_height);
    data->playerdown = mlx_xpm_file_to_image(data->mlx_ptr, "images/playerdown.xpm", &data->img_width, &data->img_height);
    data->exit_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/lastexit.xpm", &data->img_width, &data->img_height);
    data->collect_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/lastcollect.xpm", &data->img_width, &data->img_height); 
}
void    number_of_collectibles(t_data *data)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (data->map_real[j])
    {
        i = 0;
        while (data->map_real[j][i])
        {
            if(data->map_real[j][i] == 'C')
                data->collectibles++;
            i++;
        }
        j++;
    }
    printf("%d\n", data->collectibles);
}