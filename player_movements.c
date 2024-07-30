/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:28:48 by rboulaga          #+#    #+#             */
/*   Updated: 2024/07/30 11:15:25 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    left(t_data *data)
{
    int i = 0;
    
    if (data->xP-1 != 1)
    {
        
    }
}


int    player_movements(int key, t_data *data)
{  
    
    if (key == 97)
        left(data);
    if (key == 119)
         write (1, "hello world", 11);
    if (key == 100)
        write (1, "hello world", 11);
    if (key == 115)
        write (1, "hello world", 11);
    return (0);
}

// w = 119 up
// s = 115 down
// D = 100 right

//a = left 97
//
//