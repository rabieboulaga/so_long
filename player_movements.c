/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:28:48 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/07 17:03:02 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_data *data)
{
	if (data->map_real[data->yp][data->xp - 1] != '1'
		&& data->map_real[data->yp][data->xp - 1] != 'E')
	{
		if (data->map_real[data->yp][data->xp - 1] == 'C'
			&& data->collectibles != 0)
			data->collectibles--;
		data->map_real[data->yp][data->xp] = '0';
		data->map_real[data->yp][data->xp - 1] = 'P';
		put_all_images(data, 'P', data->playerleft);
		put_all_images(data, '0', data->background_image);
		data->xp -= 1;
		data->number_of_moves++;
		put_str("Number of mover : ", data->number_of_moves);
	}
	else if (data->map_real[data->yp][data->xp - 1] == 'E'
			&& data->collectibles == 0)
	{
		data->number_of_moves++;
		put_str("Number of mover : ", data->number_of_moves);
		write(1, "you win\n", 8);
		free_images(data);
	}
}

void	right(t_data *data)
{
	if (data->map_real[data->yp][data->xp + 1] != '1'
		&& data->map_real[data->yp][data->xp + 1] != 'E')
	{
		if (data->map_real[data->yp][data->xp + 1] == 'C'
			&& data->collectibles != 0)
			data->collectibles--;
		data->map_real[data->yp][data->xp] = '0';
		data->map_real[data->yp][data->xp + 1] = 'P';
		put_all_images(data, 'P', data->playerright);
		put_all_images(data, '0', data->background_image);
		data->xp += 1;
		data->number_of_moves++;
		put_str("Number of mover : ", data->number_of_moves);
	}
	else if (data->map_real[data->yp][data->xp + 1] == 'E'
			&& data->collectibles == 0)
	{
		data->number_of_moves++;
		put_str("Number of mover : ", data->number_of_moves);
		write(1, "you win\n", 8);
		free_images(data);
	}
}

void	up(t_data *data)
{
	if (data->map_real[data->yp - 1][data->xp] != '1' && data->map_real[data->yp
		- 1][data->xp] != 'E')
	{
		if (data->map_real[data->yp - 1][data->xp] == 'C'
			&& data->collectibles != 0)
			data->collectibles--;
		data->map_real[data->yp][data->xp] = '0';
		data->map_real[data->yp - 1][data->xp] = 'P';
		put_all_images(data, 'P', data->playerup);
		put_all_images(data, '0', data->background_image);
		data->yp -= 1;
		data->number_of_moves++;
		put_str("Number of mover : ", data->number_of_moves);
	}
	else if (data->map_real[data->yp - 1][data->xp] == 'E'
			&& data->collectibles == 0)
	{
		data->number_of_moves++;
		put_str("Number of moves : ", data->number_of_moves);
		write(1, "you win\n", 8);
		free_images(data);
	}
}

void	down(t_data *data)
{
	if (data->map_real[data->yp + 1][data->xp] != '1' && data->map_real[data->yp
		+ 1][data->xp] != 'E')
	{
		if (data->map_real[data->yp + 1][data->xp] == 'C'
			&& data->collectibles != 0)
			data->collectibles--;
		data->map_real[data->yp][data->xp] = '0';
		data->map_real[data->yp + 1][data->xp] = 'P';
		put_all_images(data, 'P', data->playerdown);
		put_all_images(data, '0', data->background_image);
		data->yp += 1;
		data->number_of_moves++;
		put_str("Number of moves : ", data->number_of_moves);
	}
	else if (data->map_real[data->yp + 1][data->xp] == 'E'
			&& data->collectibles == 0)
	{
		data->number_of_moves++;
		put_str("Number of moves : ", data->number_of_moves);
		write(1, "you win\n", 8);
		free_images(data);
	}
}

int	player_movements(int key, t_data *data)
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
	else if (key == 65307)
		close_window(data);
	return (0);
}
