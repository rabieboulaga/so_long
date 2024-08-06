/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:35:58 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/06 13:53:13 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int main(int ac, char **av)
{
    t_data *data;

    data = malloc(sizeof(t_data));
	ft_memset(data, 0, sizeof(t_data));
    parsing(ac, av, data);
    if (data->x > 38 || data->y > 21)
        safe_exit(1 , data, 0);
    display_map(data);
}
