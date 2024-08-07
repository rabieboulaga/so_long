/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:00:02 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/07 16:19:07 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

typedef struct c_stack
{
	int		fd;
	char	**map_real;
	char	**map_copie;
	int		x;
	int		y;
	int		p;
	int		c;
	int		e;
	int		xp;
	int		yp;
	int		xe;
	int		ye;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*background_image;
	void	*wall_image;
	void	*playerright;
	void	*playerleft;
	void	*playerup;
	void	*playerdown;
	void	*collect_image;
	void	*exit_image;
	int		img_width;
	int		img_height;
	int		collectibles;
	int		number_of_moves;
}			t_data;

char		*get_next_line(int fd);
char		*read_for_me(char *reminder, int fd, char *buff);
size_t		ft_strlenn(char *str);
char		*ft_strjoinn(char *s1, char *s2);
char		*ft_strdupp(char *s);
char		*ft_strchrr(char *s, int c);
char		*leftside(char *reminder);
char		*rightside(char *reminder);
void		parsing(int ac, char **av, t_data *data);
void		*ft_memset(void *b, int c, size_t len);
void		safe_exit(int nothing, t_data *data, int order);
void		check_map(t_data *data);
void		free_map(char **str);
int			ft_strlen(char *str);
int			remove_newline(char **str);
void		map_copie(t_data *data);
void		coordinates(t_data *data);
void		flood_fill(int x, int y, char **str);
void		find_item(t_data *data, char c);
void		display_map(t_data *data);
void		images_data(t_data *data);
void		put_images(t_data *data);
void		put_all_images(t_data *data, char c, void *images);
int			player_movements(int key, t_data *data);
void		number_of_collectibles(t_data *data);
void		put_moves(int num);
void		put_str(char *str, int num);
void		free_images(t_data *data);
void		the_end(int nothing, t_data *data, int order);
void		images_data2(t_data *data);
int			close_window(t_data *data);
void		flood_fill_exit(int x, int y, char **str);

# endif
#endif
