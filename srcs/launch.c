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

int		key_hooks(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		l_r_up_down(data->mlx, data->env, keycode);
	else if (keycode == R || keycode == F)
		depth(data->mlx, data->env, keycode);
	else if (keycode == Y || keycode == H)
		zoom(data->mlx, data->env, keycode);
	else if (keycode == Q || keycode == E)
		rot(data->mlx, data->env, keycode);
	else if (keycode == TAB)
		normal_mod(data->mlx, data->env, keycode);
	return (0);
}

void	relaod_fdf(t_mlx *mlx, t_env *env)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	parse(env);
	print_vertical_lines(mlx, env);
	print_horizontal_lines(mlx, env);
}

void	launch_fdf(t_mlx *mlx, t_env *env)
{
	t_data		data;

	data.mlx = mlx;
	data.env = env;
	mlx_key_hook(mlx->window, key_hooks, &data);
	mlx_loop(mlx->mlx);
}
