/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	depth(t_mlx *mlx, t_env *env, int keycode)
{
	env->depth += keycode == R ? 1 : -1;
	relaod_fdf(mlx, env);
}

void	zoom(t_mlx *mlx, t_env *env, int keycode)
{
	env->view.x += keycode == Y ? 2 : -2;
	env->view.y = env->view.x / 2;
	relaod_fdf(mlx, env);
}

void	normal_mod(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == TAB)
	{
		env->rot.y = 0;
		env->rot.x = 0;
		env->view.x = 20;
		env->view.y = 10;
		env->depth = 4;
	}
	relaod_fdf(mlx, env);
}

void	rot(t_mlx *mlx, t_env *env, int keycode)
{
	env->view.x += keycode == Q ? 10 : -10;
	relaod_fdf(mlx, env);
}

void	l_r_up_down(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == D || keycode == A)
		env->rot.x += keycode == D ? 10 : -10;	
	else if (keycode == S || keycode == W)
	{
		env->rot.x += keycode == S ? 10 : -10;
		env->rot.y += keycode == S ? 10 : -10;	
	}
	relaod_fdf(mlx, env);
}
