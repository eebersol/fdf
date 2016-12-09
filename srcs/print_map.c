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

// void     do_key_press(MLXWindow *win, data_t *data, unsigned key)
// {
//     if (key == MLX_KEY_ESC)
//         mlx_loop_stop(data->mlx_ptr);
// }


  // tempPt.x = (2 * pt.y + pt.x) / 2
  // tempPt.y = (2 * pt.y - pt.x) / 2



// int xtemp = xs / (W / 2);
// int ytemp = ys / (H / 2);
// int xt = (xs - ys) / 2;
// int yt = ytemp + xt;


void	print_map(void)
{
	t_env 	*env;
	t_list 	*list;
	t_point	*point;
	void 	*mlx;
	void 	*win;
	double 	x;
	double 	y;
	int i;

	x = 1;
	y = 1;
	env = recover_env();
	list = env->list;
	mlx = mlx_init();
	win = mlx_new_window(mlx, env->height, env->width, "fdf");
	// print_line_hori(10, 10, env->height - 1, 10 , mlx, win);
	i = 0;
	list = list->next;
	while (list)
	{
		point = list->content;
		printf("X : [%f] ->[%f]\n", x, point->x);
		printf("Y : [%f] ->[%f]\n", y, point->y);
		// print_line_hori(x, y, point->x, point->y, mlx, win);
		print_verti(x, y, point->x, point->y, mlx, win);
		// x = point->x;
		if (!list->next)
			break;
		list = list->next;
		i++;
	}
	mlx_loop(mlx);
}

// void	print_map(void)
// {
// 	t_env *env;
// 	void 	*mlx;
// 	double i;
// 	void 	*win;
// 	double 	x;
// 	double x1;
// 	double 	y;
// 	double y1;

// 	env = recover_env();
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, env->height, env->width, "fdf");
// 	i = 0;
// 	x = (2 * 10 + 10) / 2;
// 	y = (2 * 10 - 10) / 2;
// 	// printf("x->%f y->%f\n", x, y);
// 	x1 = env->height - 1;
// 	y1 = env->width - 1;
// 	while (i < env->twidth)
// 	{
// 		print_line_hori(x, y, x1, y, mlx, win);
// 		y += (env->width/env->twidth) / 2;
// 		i++;
// 	}
// 	i = 0;
// 	y = 10;
// 	while (i < env->theight)
// 	{
// 		print_verti(x, y, x, y1, mlx, win);
// 		x += (env->height/env->theight) / 2;
// 		i++;
// 	}
// 	mlx_loop(mlx);
// }

void	print_line_hori(double x1, double y1, double x2, double y2, void *mlx, void *win)
{
	double x;
	double y;
	(void)y2;

	y = y1;
	x = x1;
	// x2 = (2 * y2 - x2)/2
	while (x < x2)
	{
		// mlx_pixel_put(mlx, win, (2 * y - x)/2, (2 * y + x)/2, 0X00FFFFFF);
		mlx_pixel_put(mlx, win, x, y, 0X00FFFFFF);
		x++;
	}
}

void	print_verti(double x1, double y1, double x2, double y2, void *mlx, void *win)
{
	double x;
	double y;
	(void)x2;

	y = y1;;
	x = x1;
	// y2 = (2 * y2 + x)/2
	while (y < y2)
	{
	// 	mlx_pixel_put(mlx, win, (2 * y - x)/2, (2 * y + x)/2, 0X00FFFFFF);
		mlx_pixel_put(mlx, win, y, x, 0X00FFFFFF);
		y++;
	}
}