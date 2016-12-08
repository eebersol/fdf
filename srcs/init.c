/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_env		*recover_env(void)
{
	static t_env	env;

	return (&env);
}

void		init_env(void)
{
	t_env		*env;

	env = recover_env();
	env->winsize = 0;
	env->grille_value = NULL;
	env->list = NULL;
	env->point = init_point();
}


t_point		*init_point(void)
{
	t_point *point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->s = 0;
	point->z_color = 0;
	return (point);
}