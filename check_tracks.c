/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tracks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:43:31 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/06 14:39:58 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    images_data2(t_data *data)
{
    data->playerup = mlx_xpm_file_to_image(data->mlx_ptr,
        "textures/playerup.xpm", &data->img_width, &data->img_height);
    if (data->wall_image == NULL)
        free_images(data);
    data->playerdown = mlx_xpm_file_to_image(data->mlx_ptr, 
        "textures/playerdown.xpm", &data->img_width, &data->img_height);
    if (data->wall_image == NULL)
        free_images(data);
    data->exit_image = mlx_xpm_file_to_image(data->mlx_ptr,
        "textures/lastexit.xpm", &data->img_width, &data->img_height);
    if (data->wall_image == NULL)
        free_images(data);
    data->collect_image = mlx_xpm_file_to_image(data->mlx_ptr, 
        "textures/lastcollect.xpm", &data->img_width, &data->img_height); 
    if (data->wall_image == NULL)
        free_images(data);
}

void find_item(t_data *data, char c)
{
    int i;
    int j;

    j = 0;
    
    while (data->map_copie[j])
    {
        i = 0;
        while (data->map_copie[j][i] && data->map_copie[j][i] != c )
            i++;
        if (data->map_copie[j][i] == c)
            safe_exit(1, data, 0); 
        j++;
    }      
}

void    coordinates(t_data *data)
{   
    while (data->map_copie[data->yP])
    {
        data->xP = 0;
        while (data->map_copie[data->yP][data->xP] && data->map_copie[data->yP][data->xP] != 'P')
            data->xP++;
        if (data->map_copie[data->yP][data->xP] == 'P')
            break;
        data->yP++;
    }
    while (data->map_copie[data->yE])
    {
        data->xE = 0;
        while (data->map_copie[data->yE][data->xE] && data->map_copie[data->yE][data->xE] != 'E')
            data->xE++;
        if (data->map_copie[data->yE][data->xE] == 'E')
            break;
        data->yE++;
    }
}
void    flood_fill_E(int x, int y, char **str)
{ 
    if (str[y][x] == 'E')
    {
            str[y][x] = 'X';
        flood_fill(x + 1, y, str);
        flood_fill(x - 1, y, str);
        flood_fill(x, y + 1, str);
        flood_fill(x, y - 1, str);
    }          
}

void    flood_fill(int x, int y, char **str)
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