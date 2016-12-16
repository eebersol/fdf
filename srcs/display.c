/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:00:21 by eebersol          #+#    #+#             */
/*   Updated: 2015/03/23 21:37:58 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_x(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x / (double)delta.abs_x;
	dy = (double)delta.y / (double)delta.abs_x;
	i = -1;
	while (++i <= delta.abs_x)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, posx, posy + 0.5, GRN);
		posx += dx;
		posy += dy;
	}
}

void	print_y(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x / (double)delta.abs_y;
	dy = (double)delta.y / (double)delta.abs_y;
	i = -1;
	while (++i <= delta.abs_y)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, posx + 0.5, posy, GRN);
		posx += dx;
		posy += dy;
	}
}

void	print_line(t_mlx *mlx, t_point start, t_point end)
{
	t_delta	delta;
	double	posx;
	double	posy;

	init_delta(&delta, start, end);
	posx = start.x;
	posy = start.y;
	if (delta.abs_y > delta.abs_x)
		print_y(delta, mlx, posx, posy);
	else
		print_x(delta, mlx, posx, posy);
}

void	print_vertical_lines(t_mlx *mlx, t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->height - 1)
	{
		x = -1;
		while (++x < env->tab_width[y] - 1)
			print_line(mlx, env->coord[y][x], env->coord[y][x + 1]);
		print_line(mlx, env->coord[y][env->tab_width[y] - 1],
								env->coord[y + 1][env->tab_width[y] - 1]);
	}
}

void	print_horizontal_lines(t_mlx *mlx, t_env *env)
{
	int		x;
	int		y;
	int 	i;

	x = -1;
	i = -1;
	while (++i < env->height - 1)
	{
		while (++x < env->tab_width[i] - 1)
		{
			y = -1;
			while (++y < env->height - 1)
				print_line(mlx, env->coord[y][x], env->coord[y + 1][x]);
			print_line(mlx, env->coord[env->height - 1][x],
									env->coord[env->height - 1][x + 1]);
		}
	}
}
