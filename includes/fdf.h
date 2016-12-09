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

typedef struct		s_env
{
	double 			theight;
	double 			twidth;
	double			x_size;
	double			y_size;
	double 			**grille_value;
	double 			height;
	double 			width;
	t_list 			*list;
	t_point 		*point;
}					t_env;
/*
// parse_map
*/
void		parse_map(char *map);
void 	put_value_tolist(void);
void 	get_mapinfo(int fd);
/*
// init
*/
t_env		*recover_env(void);
void		init_env(void);
t_point		*init_point(void);
void	print_line_hori(double x1, double y1, double x2, double y2, void *mlx, void *win);
void	print_verti(double x1, double y1, double x2, double y2, void *mlx, void *win);
void			print_map(void);

#endif