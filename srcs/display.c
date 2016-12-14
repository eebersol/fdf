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

#include <fdf.h>

void	draw_horz_line(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x/(double)delta.abs_x;
	dy = (double)delta.y/(double)delta.abs_x;
	i = 0;
	while (i <= delta.abs_x)
	{
		printf("X -> [%f}--[%f]\n", posx, posy);
		mlx_pixel_put(mlx->mlx, mlx->window, (int)posx, (int)(posy + 0.5), RD);
		posx += dx;
		posy += dy;
		i++;
	}
}

void	draw_vert_line(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x/(double)delta.abs_y;
	dy = (double)delta.y/(double)delta.abs_y;
	i = 0;
	while (i <= delta.abs_y)
	{
		printf(" Y [%f]--[%f]\n", posx, posy);
		mlx_pixel_put(mlx->mlx, mlx->window, (int)(posx + 0.5), (int)posy, RD);
		posx += dx;
		posy += dy;
		i++;
	}
}

void		draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_delta	delta;
	double	posx;
	double	posy;

	init_delta(&delta, start, end);
	posx = start.x;
	posy = start.y;
	printf("posx [%f] posy [%f]\n", posx, posy);
	if (delta.abs_y > delta.abs_x)
		draw_vert_line(delta, mlx, posx, posy);
	else
		draw_horz_line(delta, mlx, posx, posy);
}


void	draw_vertical_lines(t_mlx *mlx, t_env *env)
{
	int		x;
	int		y;
	int		height;
	int		width;

	height = env->height;
	width = env->width;
	y = 0;
	while (y < height - 1)
	{
		x = 0;
		while (x < width - 1)
		{
			draw_line(mlx, env->coord[y][x], env->coord[y][x + 1]);
			x++;
		}
		draw_line(mlx, env->coord[y][env->width - 1], env->coord[y + 1][env->width - 1]);
		y++;
	}
}

void	draw_horizontal_lines(t_mlx *mlx, t_env *env)
{
	int		x;
	int		y;
	int		height;
	int		width;

	height = env->height;
	width = env->width;
	x = 0;
	while (x < width - 1)
	{
		y = 0;
		while (y <  height - 1)
		{
			draw_line(mlx, env->coord[y][x], env->coord[y + 1][x]);
			y++;
		}
		draw_line(mlx, env->coord[env->height - 1][x], env->coord[env->height - 1][x + 1]);
		x++;
	}
}
