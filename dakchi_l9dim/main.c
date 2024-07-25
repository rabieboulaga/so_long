/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:35:58 by rboulaga          #+#    #+#             */
/*   Updated: 2024/06/14 05:03:44 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int main(int ac, char **av)
{
    t_data data;
    
    ft_memset(&data, 0, sizeof(t_data));
    (void)ac;
    parsing(ac, av, &data);
    printf("%s", data.str_map);
}