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
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

#define PADDING_X		700
#define PADDING_Y		200
#define WINDOW_SIZE_X	1920
#define WINDOW_SIZE_Y	1080
#define RD				0xEC354C
typedef struct s_point
{
	int 		x;
	int 		y;
	int 		z_color;
}				t_point;

typedef struct		s_env
{
	char 			*file_name;
	int 			fd;
	int				height;
	int 			width;
	int				depth;
	t_point 		view;
	t_point 		**point;
	t_point			**coord;
	t_list 			*list;
	int 			**height_tile;
}					t_env;


typedef struct		s_mlx
{
	double		height;
	double		width;
	void		*mlx;
	void		*window;
}					t_mlx;

typedef struct	s_data
{
	t_env	*env;
	t_mlx	*mlx;
}				t_data;

typedef struct	s_delta
{
	int		x;
	int		y;
	int		abs_x;
	int		abs_y;
}				t_delta;
/*
// parse_map
*/
void		parse_map(char *map);
void 		put_value_tolist(void);
void 		get_mapinfo(int fd);
/*
// init
*/
t_env		*recover_env(void);
t_mlx		*recover_mlx(void);
void		init_env(void);
t_mlx		*init_mlx(void);
t_point		*init_point(void);
void		print_line_hori(double x1, double y1, double x2, double y2, void *mlx, void *win);
void		print_verti(double x1, double y1, double x2, double y2, void *mlx, void *win);
void		print_map(void);

/*
// display.c
*/
void		init_delta(t_delta *delta, t_point start, t_point end);
void		draw_horz_line(t_delta delta, t_mlx *mlx, double posx, double pos);
void		draw_vert_line(t_delta delta, t_mlx *mlx, double posx, double posy);
void		draw_line(t_mlx *mlx, t_point start, t_point end);
void		draw_horizontal_lines(t_mlx *mlx, t_env *env);
void		draw_vertical_lines(t_mlx *mlx, t_env *env);

/*
// get_info.c
*/
void		parse();
void		get_width_height_map();
void		read_file();

#endif