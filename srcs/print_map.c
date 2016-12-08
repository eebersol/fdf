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

void     do_key_press(MLXWindow *win, data_t *data, unsigned key)
{
    if (key == MLX_KEY_ESC)
        mlx_loop_stop(data->mlx_ptr);
}

int           print_map(void)
{
    data_t    data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_window_create(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_window_hook_event(data.mlx_win, MLX_HOOK_KEY_PRESS, do_key_press, &data);
    mlx_loop_start(data.mlx_ptr);
    mlx_window_destroy(data.mlx_ptr, data.mlx_win);
    mlx_deinit(data.mlx_ptr);
    return (EXIT_SUCCESS);
}