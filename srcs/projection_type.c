/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void  cartesian_to_isometric(void)
{
	t_point *point;
	t_list *cur;
	t_point	*iso_point;
	t_env *env;

	env = recover_env();
	cur = (t_list*)malloc(sizeof(t_list));
	while (env->list)
	{
		point = env->list->content;
		iso_point = init_point();
		// iso_point->x = (point->x - point->y) * (env->twidth/2);
		iso_point->x = (2 * point->y - point->x)/2;
		// iso_point->y = (point->x + point->y) * (env->theight/2);
		iso_point->y = (2 * point->y + point->x)/2;
		ft_lstaddend(&cur, ft_lstnew(iso_point, sizeof(t_point)));
		if (!env->list->next)
			break;
		env->list = env->list->next;
	}
	env->list = cur;
}
