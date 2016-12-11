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


// screen.x = (map.x - map.y) * TILE_WIDTH_HALF;
// screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;

// static void	print_y(double x1, double y1, double y2, void *mlx, void *win)
// {
// 	double isoX;
// 	double isoY;

// 	// isoX = x1 - y1 + recover_env()->width * 0.5;
// 	// isoY = 0 + x1 * 0.5 + y1 * 0.5 + recover_env()->height * 0.3;
// 	// x1 = isoX;
// 	// y1 = isoY;
// 	isoX = (x1 - y1) * (recover_env()->twidth/2);
// 	isoY = (x1 + y1) * (recover_env()->theight/2);
// 	// x1 = isoX;
// 	// y1 = isoY;
// 	while (y1 < y2)
// 	{
// 		// mlx_pixel_put(mlx, win, (2 * y1 - x1)/2, (2 * y1 + x1)/2, 0X00FFFFFF);
// 		mlx_pixel_put(mlx, win, x1, y1, 0X00FFFFFF);
// 		// mlx_pixel_put(mlx, win, x1, (x1 + y1) * (recover_env()->theight/2), 0X00FFFFFF);erm
// 		y1++;
// 	}
// }

// static void	print_x(double x1, double y1, double x2, void *mlx, void *win)
// {
// 	double isoX;
// 	double isoY;

// 	// isoX = x1 - y1 + recover_env()->width * 0.5;
// 	// isoY = 0 + x1 * 0.5 + y1 * 0.5 + recover_env()->height * 0.3;
// 	// x1 = isoX;
// 	// y1 = isoY;
// 	isoX = (x1 - y1) * (recover_env()->twidth/2);
// 	isoY = (x1 + y1) * (recover_env()->theight/2);
// 	// x1 = isoX;
// 	// y1 = isoY;
// 	while (x1 < x2)
// 	{
// 		// mlx_pixel_put(mlx, win, (2 * y1 - x1)/2, (2 * y1 + x1)/2, 0X00FFFFFF);
// 		mlx_pixel_put(mlx, win, x1, y1, 0X00FFFFFF);
// 		// mlx_pixel_put(mlx, win, (x1 - y1) * (recover_env()->twidth/2), y1, 0X00FFFFFF);
// 		x1++;
// 	}
// }

// void	print_map(void)
// {
// 	t_env 	*env;
// 	void 	*mlx;
// 	void 	*win;
// 	double 	x;
// 	double 	y;
// 	double 	i;

// 	env = recover_env();
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, env->height, env->width, "fdf");
// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	while (i < env->y_size)
// 	{
// 		print_y(x, y, (env->y_size * env->theight), mlx, win);
// 		x += env->twidth;
// 		i++;
// 	}
// 	x = 0;
// 	i = 0;
// 	while (i < env->x_size)
// 	{	
// 		print_x(x, y, (env->x_size * env->twidth), mlx, win);
// 		y += env->theight;
// 		i++;
// 	}
// 	mlx_loop(mlx);
// }

// void	print_line_hori(double x1, double y1, double x2, double y2, void *mlx, void *win)
// {
// 	double x;
// 	double y;
// 	(void)y2;

// 	y = y1;
// 	x = x1;
// 	// x2 = (2 * y2 - x2)/2
// 	while (x < x2)
// 	{
// 		// mlx_pixel_put(mlx, win, (2 * y - x)/2, (2 * y + x)/2, 0X00FFFFFF);
// 		mlx_pixel_put(mlx, win, x, y, 0X00FFFFFF);
// 		x++;
// 	}
// }
static void	print_x(double x1, double y1, double x2, void *mlx, void *win)
{

	while (x1 < x2)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFFFFF);
		// mlx_pixel_put(mlx, win, (2 * y1 - x1)/2, (2 * y1 + x1)/2, 0X00FFFFFF);
		x1++;
	}
}

static void	print_y(double x1, double y1, double y2, void *mlx, void *win)
{
	while (y1 < y2)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFFFFF);
		// mlx_pixel_put(mlx, win, (2 * y1 - x1)/2, (2 * y1 + x1)/2, 0X00FFFFFF);
		y1++;
	}
}
void	print_map(void)
{
	t_env 	*env;
	t_point *point;
	t_point	*more_point;
	t_list *cur;
	t_list *tmp;
	double b;
	double c;
	int i;
	void 	*mlx;
	void 	*win;

	env = recover_env();
	mlx = mlx_init();
	c = (env->twidth * 0.6);
	win = mlx_new_window(mlx, env->height, env->width, "fdf");
	cur = env->list;
	tmp = env->list;
	tmp = tmp->next;
	i = 0;
	while (tmp)
	{
		point = cur->content;
		more_point = tmp->content;
		if (i == 0)
			b = point->y;
		printf("X : de [%f] a [%f]\n", point->x, more_point->x);
		printf(" height : [%f] Y : de [%f] a [%f]\n", env->height, b, (env->height - (env->len_map * 2)));
		print_x(point->x, point->y, more_point->x, mlx, win);
		print_y(point->x, point->y, more_point->y, mlx, win);
		i++;
		if (!tmp->next)
		{
			break;
		}
		cur = cur->next;
		tmp = tmp->next;
	}
	printf("[%d]\n", i);
	mlx_loop(mlx);
}

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

