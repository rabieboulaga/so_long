/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:00:02 by rboulaga          #+#    #+#             */
/*   Updated: 2024/06/12 22:53:20 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

typedef struct c_stack
{
	int				fd;
    char            *str_map;
    char            *safe_map;
	long long		data;
}					t_data;

char	*get_next_line(int fd);
char	*read_for_me(char *reminder, int fd, char *buff);
size_t	ft_strlenn(char *str);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strdupp(char *s);
char	*ft_strchrr(char *s, int c);
char	*leftside(char *reminder);
char	*rightside(char *reminder);
void    parsing(int ac, char **av);





# endif
#endif