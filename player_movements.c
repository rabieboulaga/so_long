/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:28:48 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/01 20:47:55 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    left(t_data *data)
{    
    if (data->map_real[data->yP][data->xP - 1] != '1')
    {
        if (data->map_real[data->yP][data->xP - 1] == 'C' && data->collectibles != 0)
            data->collectibles--;
        put_str("Number if collectibels : ", data->collectibles);
        data->map_real[data->yP][data->xP] = '0';
        data->map_real[data->yP][data->xP - 1] = 'P';
        put_all_images(data, 'P', data->playerleft);
        put_all_images(data, '0', data->background_image);
        data->xP -= 1;
        data->number_of_moves++;
        put_str("Number of mover : ", data->number_of_moves);
    }
}

void    right(t_data *data)
{
    if (data->map_real[data->yP][data->xP + 1] != '1')
    {
        if (data->map_real[data->yP][data->xP + 1] == 'C' && data->collectibles != 0)
            data->collectibles--;
        put_str("Number if collectibels : ", data->collectibles);
        data->map_real[data->yP][data->xP] = '0';
        data->map_real[data->yP][data->xP + 1] = 'P';
        put_all_images(data, 'P', data->playerright);
        put_all_images(data, '0', data->background_image);
        data->xP += 1;
        data->number_of_moves++;
        put_str("Number of mover : ", data->number_of_moves);
    }
    else if (data->map_real[data->yP][data->xP + 1] == 'E' &&)
    {
        
    }
}
void    up(t_data *data)
{
    if (data->map_real[data->yP - 1][data->xP] != '1')
    {
        if (data->map_real[data->yP - 1][data->xP] == 'C' && data->collectibles != 0)
            data->collectibles--;
        put_str("Number if collectibels : ", data->collectibles);
        data->map_real[data->yP][data->xP] = '0';
        data->map_real[data->yP - 1][data->xP] = 'P';
        put_all_images(data, 'P', data->playerup);
        put_all_images(data, '0', data->background_image);
        data->yP -= 1;
        data->number_of_moves++;
        put_str("Number of mover : ", data->number_of_moves);
    }
}

void    down(t_data *data)
{
    if (data->map_real[data->yP + 1][data->xP] != '1')
    {
        if (data->map_real[data->yP + 1][data->xP] == 'C' && data->collectibles != 0)
            data->collectibles--;
        put_str("Number if collectibels : ", data->collectibles);
        data->map_real[data->yP][data->xP] = '0';
        data->map_real[data->yP + 1][data->xP] = 'P';
        put_all_images(data, 'P', data->playerdown);
        put_all_images(data, '0', data->background_image);
        data->yP += 1;
        data->number_of_moves++;
        put_str("Number of mover : ", data->number_of_moves);
    }
}

int    player_movements(int key, t_data *data)
{  
    (void)data;
    if (key == 97)
        left(data);
    else if (key == 100)
        right(data);    
    else if (key == 119)
        up(data);
    else if (key == 115)
        down(data);    
    return (0);
}

// w = 119 up
// s = 115 down
// D = 100 right

//a = left 97
//
//