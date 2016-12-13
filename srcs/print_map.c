/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>


static void	print_x(double x1, double y1, double x2, double z,void *mlx, void *win, int color)
{
	(void)z;
	while (x1 < x2)
	{
		mlx_pixel_put(mlx, win, ((2 * x1 - y1)/1.5), ((2 * x1 + y1)/1.5), color);
		x1++;
	}
}

	

static void	print_y(double x1, double y1, double y2, double z, void *mlx, void *win, int color)
{	
	(void)z;
	while (y1 <= y2)
	{
			mlx_pixel_put(mlx, win, ((2 * x1 - y1)/1.5), ((2 * x1 + y1)/1.5), color);
			y1++;
	}
}

void	print_map(void)
{
	t_env 	*env;
	t_point *point;
	t_point	*more_point;
	t_list 	*cur;
	t_list 	*tmp;
	double  color_x;
	double	color_y;
	int 	i;
	double j;
	void 	*mlx;
	void 	*win;

	env = recover_env();
	mlx = mlx_init();
	win = mlx_new_window(mlx, env->height, env->width, "fdf");
	cur = env->list;
	tmp = env->list;
	tmp = tmp->next;
	i = 0;
	point = env->list->content;
	point = cur->content;
	more_point = ft_lstget_at(env->list, env->x_size)->content;
	j = more_point->y - point->y;
	while (tmp)
	{
		point = cur->content;
		more_point = tmp->content;
		if (point->z < 0)
		{
			color_x = 0xFFFFFF;
			color_y = 0xFFFFFF;
		}
		else if (point->z > 0)
		{
			color_x = 0xAD4F09;
			color_y = 0xAD4F09;
		}
		else
		{
			color_x = 0x0041FF;
			color_y = 0x25FF50;	
		}
		print_x(point->x, point->y, more_point->x, point->z, mlx, win,  color_x);
		if (i < ft_lstcount(env->list) - env->x_size)
			print_y(point->x, point->y, more_point->y + j, point->z, mlx, win, color_y);
		if (!tmp->next)
			break;
		i++;
		tmp = tmp->next;
		cur = cur->next;
	}
	mlx_loop(mlx);
}

