/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:16 by rboulaga          #+#    #+#             */
/*   Updated: 2024/07/30 11:28:06 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    images_data(t_data *data)
{
    data->wall_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/img.xpm", &data->img_width, &data->img_height);
    data->background_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/my.xpm", &data->img_width, &data->img_height);
      
}
void    number_of_collectibles(t_data *data)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (data->map_real[j])
    {
        while (data->map_real[j][i])
        {
            if(data->map_real[j][i] == 'C')
                data->collectibles;
            i++;
        }
        j++;
    }
}