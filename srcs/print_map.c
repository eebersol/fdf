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


static void	print_x(double x1, double y1, double x2, void *mlx, void *win)
{
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFFFFF);
		x1++;
		y1--;
	}
}

	

static void	print_y(double x1, double y1, double y2, void *mlx, void *win)
{
	printf("[%d]\n", y1 <= y2);
	while (y1 <= y2)
	{
		mlx_pixel_put(mlx, win, x1, y1 + 50, 0X00FFFFFF);
		y1++;
		x1++;
	}
}

void	print_map(void)
{
	t_env 	*env;
	t_point *point;
	t_point	*more_point;
	t_list 	*cur;
	t_list 	*tmp;
	int 	i;
	int 	j;
	void 	*mlx;
	void 	*win;

	env = recover_env();
	mlx = mlx_init();
	win = mlx_new_window(mlx, env->height, env->width, "fdf");
	cur = env->list;
	tmp = env->list;
	tmp = tmp->next;
	i = 0;
	printf("env->list [[%d]]\n", ft_lstcount(env->list));
	printf(" cur->list[[%d]]\n", ft_lstcount(cur));
	printf("tmp->list[[%d]]\n", ft_lstcount(tmp));
	while (tmp)
	{
		j = 0;
		point = cur->content;
		more_point = tmp->content;
		i = 0;
		printf(" x de [%f] a [%f]\n", more_point->x, point->x);
		printf(" y de [%f] a [%f]\n", point->y, more_point->y);
		print_x(more_point->x, more_point->y, point->x, mlx, win);
		print_y(more_point->x, point->y, more_point->y, mlx, win);
		i++;
		cur = cur->next;
		if (!tmp->next)
		{
			break;
		}
		tmp = tmp->next;
	}
	printf("[%d] [%f][%f]\n", i, env->x_size, env->y_size);
	mlx_loop(mlx);
}
