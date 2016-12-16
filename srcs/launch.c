/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static 	void relaod_fdf(t_mlx *mlx, t_env *env)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	parse(env);
	print_vertical_lines(mlx, env);
	print_horizontal_lines(mlx, env);
}


static void	depth(t_mlx *mlx, t_env *env, int i)
{
	if (i == 0)
		env->depth = 4;
	else if (i == 1)
		env->depth += 1;
	else
		env->depth -= 1;
	relaod_fdf(mlx, env);
}

static void	zoom(t_mlx *mlx, t_env *env, int i)
{
	if (i == 0)
	{
		env->view.x = 20;
		env->view.y = 10;
	}
	else if (i == 1)
	{
		env->view.x += 1;
		env->view.y += 0.5;
	}
	else
	{
		env->view.x -= 1;
		env->view.y -= 0.5;
	}
	relaod_fdf(mlx, env);
}


static int		key_hooks(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == S)
		zoom(data->mlx, data->env, 1);
	else if (keycode == A)
		zoom(data->mlx, data->env, 2);
	else if (keycode == D)
		zoom(data->mlx, data->env, 0);
	else if (keycode == F)
		depth(data->mlx, data->env, 1);
	else if (keycode == G)
		depth(data->mlx, data->env, 2);
	else if (keycode == H)
	{
		printf("ICIhhhh\n");
		depth(data->mlx, data->env, 0);
	}
	return (0);
}

void	launch_fdf(t_mlx *mlx, t_env *env)
{
	t_data		data;

	data.mlx = mlx;
	data.env = env;
	mlx_key_hook(mlx->window, key_hooks, &data);
	mlx_loop(mlx->mlx);
}