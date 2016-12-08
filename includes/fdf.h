/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:00:21 by eebersol          #+#    #+#             */
/*   Updated: 2015/03/23 21:37:58 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

typedef struct s_point
{
	double 		x;
	double 		y;
	double		s;
	double		z;
	int 		z_color;
}				t_point;

typedef struct s_data
{
    MLXCore    *mlx_ptr;
    MLXWindow  *mlx_win;
} 				data_t;


typedef struct		s_env
{
	int 			winsize;
	int 			**grille_value;
	t_list 			*list;
	t_point 		*point;
}					t_env;
/*
// parse_map
*/
void		parse_map(char *map);
int	 **put_value_array(void);
void 	get_mapinfo(int fd);
/*
// init
*/
t_env		*recover_env(void);
void		init_env(void);
t_point		*init_point(void);

int			print_map(void);
void 		do_key_press(MLXWindow *win, data_t *data, unsigned key);

#endif