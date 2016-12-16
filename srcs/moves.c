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

# include <fdf.h>

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

void 	rot(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == Q)
	{
		env->rot.x += 10;
	}
	else
		env->rot.x -= 10;
	relaod_fdf(mlx, env);
}

void	l_r_up_down(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == D)
		env->rot.x += 10;
	else if (keycode == A)
		env->rot.x -= 10;
	else if (keycode == W)
	{
		env->rot.x -= 10;
		env->rot.y -= 10;
	}
	else if (keycode == S)
	{
		env->rot.x += 10;
		env->rot.y += 10;		
	}
	relaod_fdf(mlx, env);
}