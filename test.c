/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:38 by rboulaga          #+#    #+#             */
/*   Updated: 2024/06/10 11:10:40 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stddef.h>

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    int i = 0;

    // Initialize the MiniLibX library and get the connection pointer
    mlx_ptr = mlx_init();
 
    // Create a new window (800x600) with the title "My Window"
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "My Window");
   
    // Put a pixel at (100, 100) with the color 0xFFFFFF (white)
    
    while (i <= 100)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, 910 + i, 490, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, 910 + i, 590, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, 910 + i, 490 + i, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, 910 + i, 590 - i, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, 910 , 490 + i, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, 1010 , 490 + i, 0xFFFFFF);
        i++; 
    }
    // Enter the MiniLibX event loop
    mlx_loop(mlx_ptr);

    return 0;
}
