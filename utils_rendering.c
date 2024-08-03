/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:16 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/02 18:06:43 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_moves(int num)
{
    if (num > 9)
        put_moves(num / 10);
    write (1, &"0123456789"[num % 10], 1);    
}
void    put_str(char *str, int num)
{
    int i;
     
    i = 0;
    while (str[i])
    {
        write (1, &str[i], 1);
        i++;
    }
    put_moves(num);
    write (1, "\n", 1);
}

void    free_images(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->exit_image);
    mlx_destroy_image(data->mlx_ptr, data->collect_image);
    mlx_destroy_image(data->mlx_ptr, data->playerdown);
    mlx_destroy_image(data->mlx_ptr, data->playerleft);
    mlx_destroy_image(data->mlx_ptr, data->playerright);
    mlx_destroy_image(data->mlx_ptr, data->playerup);
    mlx_destroy_image(data->mlx_ptr, data->wall_image);
    mlx_destroy_image(data->mlx_ptr, data->background_image);
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
    mlx_destroy_display(data->mlx_ptr);
}


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