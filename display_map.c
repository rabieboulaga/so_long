/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:29:42 by rboulaga          #+#    #+#             */
/*   Updated: 2024/07/08 11:46:48 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    put_image(t_data *data)
{
    int i;
    int j;
    int x;


    i = 0;
    j = 0;
    
    data->wall_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/img.xpm", &data->img_width, &data->img_height);
    
    while (data->map_real[j])
    {
        i = 0;
        while (data->map_real[j][i])
        {
            if (data->map_real[j][i] && data->map_real[j][i] == '1')
                x = mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->wall_image, i * 50, j * 50);
            i++;
        }
        j++; 
    }
    
    data->background_image = mlx_xpm_file_to_image(data->mlx_ptr, "images/my.xpm", &data->img_width, &data->img_height);
    
    j = 0;
    while (data->map_real[j])
    {
        i = 0;
        while (data->map_real[j][i])
        {
            if (data->map_real[j][i] && data->map_real[j][i] == '0')
                x = mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->background_image, i * 50, j * 50);
            i++;
        }
        j++; 
    }
}

void    rendering(t_data *data)
{
    data->mlx_ptr = mlx_init();
    // printf("%p", data->mlx_ptr);
    //check the return value 
    data->mlx_window = mlx_new_window(data->mlx_ptr, 50 * data->x, 50 * data->y, "so_long");
    //check the return value
    put_image(data);
    mlx_loop(data->mlx_ptr);
}

void    display_map(t_data *data)
{
    rendering(data);
    
    
}

