/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parse()
{
	t_env 		*env;
	int			x;
	int			y;

	env = recover_env();
	env->coord = (t_point**)malloc(sizeof(t_point*) * env->height);
	y = 0;
	while (y < env->height)
	{
		env->coord[y] = (t_point*)malloc(sizeof(t_point) * env->width);
		x = 0;
		while (x < env->width)
		{
			env->coord[y][x].x = (x - y) * env->view.x + PADDING_X;
			env->coord[y][x].y = (x + y) * env->view.y + PADDING_Y - (env->height_tile[y][x] * (int)env->depth);
			x++;
		}
		y++;
	}
}

void	get_width_height_map()
{
	t_env 	*env;
	char	*line;
	int		height;

	height = 0;
	env = recover_env();
	line = NULL;
	while (ft_get_next_line(env->fd, &line) > 0)
	{
		ft_lstaddend(&env->list, ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1)));
		env->height++;
	}
	close(env->fd);
	env->width = ft_count_raw_aoc(ft_strsplit(line, ' '));

}

void		read_file()
{
	t_env 	*env;
	char	**tab_line;
	char 	*line;
	int		i;
	int		j;

	env = recover_env();
	if ((env->fd = open(env->file_name, O_RDONLY)) == -1)
		ft_putendl_fd("Error occured can't open map.", 2);
	get_width_height_map();
	line = NULL;
	env->height_tile = (int **)malloc(sizeof(int*) * env->height);
	i = 0;
	while (i < env->height)
	{
		tab_line = ft_strsplit(env->list->content, ' ');
		env->height_tile[i] = (int*)malloc(sizeof(int) * env->width);
		j = 0;
		while (j < env->width)
		{
			env->height_tile[i][j] = ft_atoi(&tab_line[i][j]);
			j++;
		}
		i++;
		env->list = env->list->next;
	}
	close(env->fd);
}